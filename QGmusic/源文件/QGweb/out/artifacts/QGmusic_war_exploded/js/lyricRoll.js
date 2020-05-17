
var oAudio = document.getElementsByTagName("audio")[0];
//获取传来的歌词参数
var Ly =  JSON.parse(window.localStorage.getItem("lyric"));
//歌词列表
var ul = document.getElementById("play");
//获取传来的歌名参数
var music = window.localStorage.getItem("music");
//获取传来的演唱者参数
var singer = window.localStorage.getItem("singer");
//获取传来的播放地址参数
oAudio.src = window.localStorage.getItem("src");


//监听ontimeupdate事件
oAudio.ontimeupdate = function() {

    for (var i = 0, l = Ly.length; i < l; i++) {
        // 创建歌词行
        var li = document.createElement("li");
        //显示到页面
        li.innerText = Ly[i][1];
        // 添加歌词行
        ul.appendChild(li);
    };

    for (var i = 0, l = Ly.length; i < l; i++) {
        //currentTime当前播放的时间
        if (oAudio.currentTime  >= Ly[i][0]) {
            //设置非当前的歌词行的样式
            Array.from(ul.children).forEach(function(item){
                item.style.color = "gray";
                item.style.fontSize = "1em";
            })
            //设置当前歌词行突出
            ul.children[i].style.color = "lightgray";
            ul.children[i].style.fontSize = "1.25em";
            //歌词上移
            ul.style.top = (8 - i * 2) + "em";
        };
    };

};

window.onload = function () {
    // 显示歌名和演唱者信息
    document.getElementsByTagName("h3")[0].innerText = music + " - " + singer;
}


