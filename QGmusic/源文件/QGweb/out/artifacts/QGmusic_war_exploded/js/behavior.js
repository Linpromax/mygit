
var close = document.getElementsByClassName("icon-close-cross");


for (var i = 0; i < close.length; i++) {
    close[i].onclick = function() {
        this.parentNode.parentNode.style.display = "none"; 
    };
}



var wrap = document.getElementsByClassName("wrap")[0];
var next = document.getElementsByClassName("arrow_right")[0];
var prev = document.getElementsByClassName("arrow_left")[0];
var container = document.getElementById("container");
var dots = document.getElementsByClassName("btns")[0].children; //不使用childNodes，因为空白节点会产生影响
var timer = null;
var index = 0;


next.onclick = function () {
    next_pic();
}

prev.onclick = function () {
    prev_pic();
}

autoPlay();

container.onmouseover = function () {
    clearInterval(timer);
}
container.onmouseleave = function () {
    autoPlay();  
}

for (var i = 0; i < dots.length; i++) {
    (function(i) {
        dots[i].onclick = function () {
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

function next_pic () {
    index++;
    if(index > 4){
        index = 0;
    }
    showCurrentDot();
    var newLeft = 0;
    if (getStyle(wrap).left === "-4380px") {
        newLeft = -1460;
    } else {
        newLeft = parseInt(getStyle(wrap).left) - 730;
    }
    wrap.style.left = newLeft + "px";
}

function prev_pic () {
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


function autoPlay () {
    timer = setInterval(function() { next_pic();}, 3000);
}

function showCurrentDot () {
    for(var i = 0; i < dots.length; i++) {
        dots[i].className = "";
    }
    dots[index].className = "on";
}
 
function getStyle(ele) {
    var style = null;
    if (window.getComputedStyle) {    
        style = window.getComputedStyle(ele, null);    // 非IE
    } else {
        style = ele.currentStyle;  // IE
    };
    return style;
}