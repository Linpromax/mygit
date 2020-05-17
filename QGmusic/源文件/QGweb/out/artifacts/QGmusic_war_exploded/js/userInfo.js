// 获取“用户”按钮
var userInfo = document.getElementById("userInfo");

//展示用户信息
userInfo .onmouseover = function() {
    document.getElementById("info").style.display = "block";
};
//关闭展示
userInfo .onmouseout = function() {
    document.getElementById("info").style.display = "none";
};
