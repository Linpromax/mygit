
//获取推荐歌单播放按钮
var btns = document.querySelectorAll("#popular div i.icon-bofang");
//获取分类歌单播放按钮
var categoryBtns = document.querySelectorAll("#category div div i.icon-bofang");
//推荐歌单id
var listIds = ["5005666939", "3136952023", "4939197903", "2720520270", "2858470213", "3072133338"];
//分类歌单id
var categoryIds = ["2857550594", "2829961453", "2888212971", "2873336061", "395305337",
					"3172849329", "3193358862", "2829839197", "2679916677", "2602935348"];

//获取歌单
for (var i = 0; i < btns.length; i++) {
	getMusicList(btns[i], listIds[i]);
}
for (var i = 0; i < categoryBtns.length; i++) {
	getMusicList(categoryBtns[i], categoryIds[i]);
}

function getMusicList(btn, id) {
	var lyric;
	var musics = [];
	var singers = [];

	btn.addEventListener("click", function () {
		var string = " ";
		var ids = [];
		var xhr = new XMLHttpRequest();

		xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=playlist&id=" + id, true);
		xhr.onreadystatechange = function () {
			if (xhr.readyState == 4) {
				if (xhr.status == 200) {
					//responseText 请求返回回来的数据
					var obj = JSON.parse(xhr.responseText);
					for (var i = 0; i < obj.playlist.tracks.length; i++) {
						//获取歌曲id
						ids[i] = obj.playlist.tracks[i].id;
						//获取歌曲信息
						string += '<p>' + obj.playlist.tracks[i].name + ' - ' + obj.playlist.tracks[i].ar[0].name + '<span><i class="iconfont icon-bofang"></i></span></p>';
						musics[i] = obj.playlist.tracks[i].name;
						singers[i] = obj.playlist.tracks[i].ar[0].name;
					}
					//显示歌单的歌曲列表
					var recommend = document.querySelector("#recommend");
					recommend.style.display = "block";
					recommend.children[1].innerHTML = string;

					getUrl2(0);//获取播音乐放地址
					getLyric2(0);//获取歌词
				}
			}
		}
		xhr.send();

		//获取播音乐放地址
		function getUrl2(index) {
			if (index < ids.length) {
				var xhr = new XMLHttpRequest();
				xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=song&id=" + ids[index], true);
				xhr.onreadystatechange = function () {
					if (xhr.readyState == 4) {
						if (xhr.status == 200) {
							//responseText 请求返回回来的数据
							var obj = JSON.parse(xhr.responseText);
							//为播放按钮绑定事件
							document.querySelectorAll("#recommend p span .icon-bofang")[index].onclick = function () {
								var src = obj.data[0].url;//播放地址
								window.open("playMusic.jsp");//转向音乐播放页面
								//传递播放地址、歌名、演唱者参数
								window.localStorage.setItem("src", src);
								window.localStorage.setItem("music", musics[index]);
								window.localStorage.setItem("singer", singers[index]);
							}
						}
					}
				};
				//发送请求
				xhr.send();
				getUrl2(index + 1);//递归实现多次异步请求
			}
		}

		//获取歌词
		function getLyric2(index) {
			if (index < ids.length) {
				var xhr2 = new XMLHttpRequest();
				xhr2.open("get", "https://api.imjad.cn/cloudmusic/?type=lyric&id=" + ids[index], true);
				xhr2.onreadystatechange = function () {
					if (xhr2.readyState == 4) {
						if (xhr2.status == 200) {
							//responseText 请求返回回来的数据
							var obj2 = JSON.parse(xhr2.responseText);
							//为播放按钮绑定事件
							document.querySelectorAll("#recommend p span .icon-bofang")[index].addEventListener("click", function () {
								lyric = obj2.lrc.lyric;//未处理的歌词文本
								var Ly = parseLyric2(lyric);//处理歌词
								//向音乐播放页面传递歌词参数
								window.localStorage.setItem("lyric", JSON.stringify(Ly));
							}, false);
						}
					};
				}
				//发送请求
				xhr2.send();
				getLyric2(index + 1);//递归实现多次异步请求
			}
		}

		//处理歌词文本
		function parseLyric2(text) {
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
				var value = v.replace(pattern, "");
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


	}, false);
}



