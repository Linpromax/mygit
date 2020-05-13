
var btns = document.querySelectorAll("#popular div i.icon-bofang");
var categoryBtns = document.querySelectorAll("#category div div i.icon-bofang");
var play = document.getElementById("play");
var listIds = ["5005666939", "3136952023", "4939197903", "2720520270", "2858470213", "3072133338"];
var categoryIds = ["2857550594", "2829961453", "2888212971", "2873336061", "395305337",
					"3172849329", "3193358862", "2829839197", "2679916677", "2602935348"];

for (var i = 0; i < btns.length; i++) {
	getMusicList(btns[i], listIds[i]);
}

for (var i = 0; i < categoryBtns.length; i++) {
	getMusicList(categoryBtns[i], categoryIds[i]);
}

function getMusicList(btn, id) {
	btn.addEventListener("click", function() {
		var string = '';
		var oAudio = document.getElementsByTagName('audio')[0];
		var ids = Array();
		var xhr = new XMLHttpRequest();
			xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=playlist&id=" + id, true);
			xhr.onreadystatechange = function() {
			if (xhr.readyState == 4) {
			  if (xhr.status == 200) {
				//xhr.responseText 请求返回回来的数据
				var obj = JSON.parse(xhr.responseText);
				console.log(obj);
				for(var i = 0; i < obj.playlist.tracks.length; i++) {
					ids[i] = obj.playlist.tracks[i].id;
					string += '<p>' + obj.playlist.tracks[i].name + ' - ' + obj.playlist.tracks[i].ar[0].name + '<span><i class="iconfont icon-bofang"></i></span></p>';
				}
				var recommend = document.querySelector("#recommend");
				recommend.style.display = "block";
				recommend.children[1].innerHTML = string;
				getUrl2(0);
				}
			  }
			}
			xhr.send();
		
	
	
			function getUrl2(index) {
				if (index < ids.length) { 
					var xhr = new XMLHttpRequest();
					xhr.open("get", "https://api.imjad.cn/cloudmusic/?type=song&id=" + ids[index], true);
					xhr.onreadystatechange = function() {
					if (xhr.readyState == 4) {
					  if (xhr.status == 200) {
						//xhr.responseText 请求返回回来的数据
						var obj = JSON.parse(xhr.responseText);
						document.querySelectorAll("#recommend p span .icon-bofang")[index].onclick = function(){
							oAudio.src = (obj.data[0].url);
							play.style.display = "flex";
						}
					  }
					}
				  };//获到请求的数据之后要做的事情
				//第三步，发送请求
					xhr.send();	
					getUrl2(index + 1);
					}
			}	
	}, false);
}


function getCategory() {

}