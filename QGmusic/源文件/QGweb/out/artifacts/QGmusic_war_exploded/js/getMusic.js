
var resultBox = document.getElementById("resultBox");
var searchResult = document.getElementById("searchResult");
var play = document.getElementById("play");
var ids = new Array();


function cb(data) {
  var oData = document.getElementById('data'),
	oAudio = document.getElementsByTagName('audio')[0];

  if (data.code == 200) {  // 正确返回内容

	try {

		showResult();

	} catch (e) {

	  oAudio.load();  // 搜索出错重载音频 以防出错时候还有音频在播放

	}
  } else {
	  	resultBox.innerHTML = '网易云音乐:(๑•ี_เ•ี๑)';  // 返回代码不是200
  }


function showResult() {
	searchResult.style.display = "block";
	var string = "";

	if(data.result.songs.length == 0) {
		string = "<h3>搜索内容为空</h3>"
	} else {
		for (var i = 0; i < data.result.songs.length; i++) {
			ids[i] = data.result.songs[i].id;
			string += '<p>' + data.result.songs[i].name + ' - ' + data.result.songs[i].artists[0].name + '<span><i class="iconfont icon-bofang"></i></span></p>';
		}
	}


	resultBox.innerHTML = string;
	getUrl(0);
	}

function getUrl(index) {
	if (index < data.result.songs.length) { 
		var xhr = new XMLHttpRequest();
		xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=song&id=" + ids[index], true);
		xhr.onreadystatechange = function() {
		if (xhr.readyState == 4) {
		  	if (xhr.status == 200) {
				//xhr.responseText 请求返回回来的数据
				var obj = JSON.parse(xhr.responseText);
				document.querySelectorAll("#resultBox p span .icon-bofang")[index].onclick = function(){
				oAudio.src = (obj.data[0].url);
				play.style.display = "flex";
			}
		  }
		}
	  };//获到请求的数据之后要做的事情
	//第三步，发送请求
		xhr.send();	
		getUrl(index + 1);
		}
	}	
}



window.onload = function () {

  	var oSearch = document.getElementById('music'),
	Btn = document.getElementById('searchMusic');
  	Btn.onclick = function () { 

	if (oSearch.value.trim()) {  // 去除输入的空格
	  	var oScirpt = document.createElement('script');
	  	oScirpt.src = 'http://s.music.163.com/search/get/?type=1&filterDj=true&limit=8&s=' + oSearch.value.trim() + '&offset=0&callback=cb';// |limit返回1条 |函数名为cb |type=1表示单曲 |offset偏移量 用于分页 | 过滤掉DJ
	  	document.body.appendChild(oScirpt);  // 将有src属性的脚本加到页面
	}
  }
};

