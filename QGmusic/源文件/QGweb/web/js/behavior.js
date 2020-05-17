//获取所有关闭按钮
var close = document.getElementsByClassName("icon-close-cross");
//一一附上点击事件
for (var i = 0; i < close.length; i++) {
    close[i].onclick = function() {
        this.parentNode.parentNode.style.display = "none"; 
    };
}

var wrap = document.getElementsByClassName("wrap")[0];//轮播图片的容器

var next = document.getElementsByClassName("arrow_right")[0];//轮播图下一页按钮

var prev = document.getElementsByClassName("arrow_left")[0];//前一页按钮

var container = document.getElementById("container");//整个轮播图模块的容器

var dots = document.getElementsByClassName("btns")[0].children; //不使用childNodes，因为空白节点会产生影响

var timer = null;

var index = 0;


next.onclick = function () {//显示下一张图
    next_pic();
}

prev.onclick = function () {//显示前一张图
    prev_pic();
}

autoPlay();

container.onmouseover = function () {//鼠标移入停止播放
    clearInterval(timer);
}

container.onmouseleave = function () {//鼠标移出自动播放
    autoPlay();  
}

for (var i = 0; i < dots.length; i++) {
    (function(i) {
        dots[i].onclick = function () {//为导航点绑定事件
        var dis = index - i;
        if(index == 4 && parseInt(getStyle(wrap).left) !== -3650) {
            dis = dis - 5;   
        }
        if(index == 0 && parseInt(getStyle(wrap).left)!== -730) {
            dis = 5 + dis;
        }
        wrap.style.left = (parseInt(getStyle(wrap).left) + dis * 730) + "px";
        index = i;
        showCurrentDot();
        }
    })(i);      
}

function next_pic () {//显示下一张图
    index++;
    if(index > 4) {//到最后一张图后自动返回第一张图
        index = 0;
    }

    showCurrentDot();//高亮当前导航点
    var newLeft = 0;

    if (getStyle(wrap).left === "-4380px") {//到最后一张图时
        newLeft = -1460;
    } else {
        newLeft = parseInt(getStyle(wrap).left) - 730;
    }
    wrap.style.left = newLeft + "px";
}

function prev_pic () {//显示前一张图
    index--;
    if(index < 0) {
        index = 4;
    }

    showCurrentDot();
    var newLeft = 0;

    if(getStyle(wrap).left === "0px") {
        newLeft = -2920;
    } else {
        newLeft = parseInt(getStyle(wrap).left) + 730;
    }
    wrap.style.left = newLeft + "px";
}

//定时播放轮播图
function autoPlay () {
    timer = setInterval(function() { next_pic();}, 3000);
}
//为当前导航点设置类名，显示高亮
function showCurrentDot () {
    for(var i = 0; i < dots.length; i++) {
        dots[i].className = "";
    }
    dots[index].className = "on";
}
//获取元素样式
function getStyle(ele) {
    var style = null;
    if (window.getComputedStyle) {    
        style = window.getComputedStyle(ele, null);    // 非IE
    } else {
        style = ele.currentStyle;  // IE
    };
    return style;
}