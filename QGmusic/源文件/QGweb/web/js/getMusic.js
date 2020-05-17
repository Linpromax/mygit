//搜索结果展示层
var searchResult = document.getElementById("searchResult");
//歌曲列表展示层
var resultBox = document.getElementById("resultBox");
//歌曲id
var ids = new Array();

//回调函数
function cb(data) {
	var lyric;

  	if (data.code == 200) {  // 正确返回内容
		try {
			showResult();//展示搜索结果
		} catch (e) {

		}
  	} else {
  		resultBox.innerHTML = "<p>网易云音乐:(๑•ี_เ•ี๑)<p/>";  // 返回代码不是200
  	}


	function showResult() {
		searchResult.style.display = "block";//显示搜索结果展示层
		var string = "";

		if (data.result.songs.length == 0) {
			string = "<h3>搜索内容为空</h3>"
		} else {
			for (var i = 0; i < data.result.songs.length; i++) {
				ids[i] = data.result.songs[i].id;//一一获取歌曲id
				//获取歌名和演唱者
				string += '<p>' + data.result.songs[i].name + ' - ' + data.result.songs[i].artists[0].name + '<span><i class="iconfont icon-bofang"></i></span></p>';
			}
		}

		resultBox.innerHTML = string;
		getUrl(0);//获取播音乐放地址
		getLyric(0);//获取歌词
		}

		//获取播音乐放地址
		function getUrl(index) {
			if (index < data.result.songs.length) {
				var xhr = new XMLHttpRequest();
				//请求网易云api获取播放地址
				xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=song&id=" + ids[index], true);
				xhr.onreadystatechange = function() {
					if (xhr.readyState == 4) {
						if (xhr.status == 200) {
							var obj = JSON.parse(xhr.responseText);//responseText 请求返回回来的数据
							//为播放按钮绑定事件
							document.querySelectorAll("#resultBox p span .icon-bofang")[index].addEventListener("click", function(){
								var src = (obj.data[0].url);
								window.open("playMusic.jsp");//转向音乐播放页面
								//传递播放地址、歌名、演唱者参数
								window.localStorage.setItem("src", src);
								window.localStorage.setItem("music", data.result.songs[index].name);
								window.localStorage.setItem("singer", data.result.songs[index].artists[0].name);
							}, false);
						}
					}
				};
				//发送请求
				xhr.send();
				getUrl(index + 1);//递归实现多次异步请求
			}
		}

  	//获取歌词
	function getLyric(index) {
		if (index < data.result.songs.length) {
			var xhr2 = new XMLHttpRequest();
			//请求网易云api获取歌词
			xhr2.open("get", "https://api.imjad.cn/cloudmusic/?type=lyric&id=" + ids[index], true);
			xhr2.onreadystatechange = function() {
				if (xhr2.readyState == 4) {
					if (xhr2.status == 200) {
						//responseText 请求返回回来的数据
						var obj2 = JSON.parse(xhr2.responseText);
						//为播放按钮绑定事件
						document.querySelectorAll("#resultBox p span .icon-bofang")[index].addEventListener("click", function(){
							lyric = obj2.lrc.lyric;//未处理的歌词
							var Ly =  parseLyric(lyric);//处理歌词
							//向音乐播放页面传递歌词参数
							window.localStorage.setItem("lyric", JSON.stringify(Ly));
						}, false);
					}
				};
			}
			//发送请求
			xhr2.send();
			getLyric(index + 1);//递归实现多次异步请求
		}
	}

	//处理歌词文本
	function parseLyric(text) {
		//将文本分隔成一行一行，存入数组
		var lines = text.split("\n");
		//用于匹配时间的正则表达式，匹配的结果类似[xx:xx.xx]或[xx:xx.xxx]
		var pattern = /\[\d{2}:\d{2}.\d{2,3}\]/g;
		//保存最终结果的数组
		var result = [];
		//去掉不含时间的行
		while (lines[0] != null && !pattern.test(lines[0])) {
			lines = lines.slice(1);
		}

		//上面用'\n'生成生成数组时，结果中最后一个为空元素，这里去掉空元素
		lines[lines.length - 1].length === 0 && lines.pop();

		lines.forEach(function(v, i, a  ) {// v 数组元素值, i 元素索引, a 数组本身
			//提取出时间[xx:xx.xx]
			var time = v.match(pattern);
			//提取纯的歌词
			var value = v.replace(pattern, '');
			//因为一行里面可能有多个时间，所以time有可能是[xx:xx.xx][xx:xx.xx][xx:xx.xx]的形式，需要进一步分隔

			time.forEach(function(v1, i1, a1) {
				//去掉时间里的中括号得到xx:xx.xx
				var t = v1.slice(1, -1).split(':');
				//转化时间，将结果压入最终数组
				result.push([parseInt(t[0], 10) * 60 + parseFloat(t[1]), value]);
			});
		});
		//将结果数组中的元素按时间大小排序
		result.sort(function(a, b) {
			return a[0] - b[0];
		});
		//去除空歌词的行
		for (var i = 0; i < result.length; ) {
			if (result[i][1] === "") {
				result.splice(i, 1);
			} else {
				i++;
			}
		}

		return result;
	}

}



window.onload = function () {
  	var oSearch = document.getElementById("music");//搜索框
	var Btn = document.getElementById("searchMusic");//搜索按钮
  	Btn.addEventListener("click", search());
	oSearch.onkeydown = function (event) {
		var theEvent = window.event || event;
		var code = theEvent.keyCode || theEvent.which;
		if (code == 13) {  //回车键的键值为13
			search();  //调用搜索事件
		}
	}

  	function search() {
		if (oSearch.value.trim()) {  // 去除输入的空格
			var oScirpt = document.createElement("script");//创建script标签
			//使用资源嵌入script实现跨域请求资源
			oScirpt.src = 'http://s.music.163.com/search/get/?type=1&filterDj=true&limit=8&s='
				+ oSearch.value.trim() + '&offset=0&callback=cb';//callback回调函数
			document.body.appendChild(oScirpt);  // 将有src属性的脚本加到页面
		}
  	}
};

