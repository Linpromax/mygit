//获取提示区域
var tips = document.getElementsByClassName("tips")[0];
//定时3秒提示自动消失
function delay() {
    setTimeout(function () {
        tips.style.display = "none";
        tips.innerHTML = "";
    }, 3000);
}
//检查表单非空
function isNotEmpty(thisform) {
    var input = thisform.getElementsByTagName("input");
    var count = thisform.getElementsByTagName("input").length;
    for(var i = 0; i < count; i++) {
        if(input[i].value == null || input[i].value == "") {//输入框为空
            tips.style.display = "block";
            tips.innerHTML = "请填写完整！";//显示提示
            delay();
            return false;
        }
    }
    return true;
}
//检查表单输入情况
function checkForm(thisform) {
    var reg1 = /^\d{11}$/;//手机号码模式
    var reg2 = /^([\u4e00-\u9fa5\·]{2,20}|[a-zA-Z\.\s]{2,20})$/;//姓名模式

    if(!isNotEmpty(thisform)) {
        return false;
    }
    if("loginForm" === thisform.name) {//为登录表单时
        let Ldata = {
            accout: thisform.getElementsByClassName("acct")[0].value,
            psw: thisform.getElementsByClassName("psw")[0].value
        };
        if(Ldata.accout.length < 8 || Ldata.accout.length > 16) {
            tips.style.display = "block";
            tips.innerHTML = "用户名应为8-16位！";
            delay();
            return false;
        }
        if(Ldata.psw.length < 8 || Ldata.psw.length > 16) {
            tips.style.display = "block";
            tips.innerHTML = "密码应为8-16位！";
            delay();
            return false;
        } 
    } else if("registForm" == thisform.name) {//为注册表单时
        let Sdata = {
            accout: thisform.getElementsByClassName("acct")[0].value,
            phone: thisform.getElementsByClassName("tel")[0].value,
            psw: thisform.getElementsByClassName("psw")[0].value,
            psw2: thisform.getElementsByClassName("psw2")[0].value,
            user: thisform.getElementsByClassName("name")[0].value
        };
        if(Sdata.accout.length < 8 || Sdata.accout.length > 16) {
            tips.style.display = "block";
            tips.innerHTML = "用户名应为8-16位！";
            delay();
            return false;
        }
        if (!reg1.test(Sdata.phone)) {
            tips.style.display = "block";
            tips.innerHTML = "请输入正确11位数字手机号码！";
            delay();
            return false;
        }
        if(Sdata.psw.length < 8 || Sdata.psw.length > 16) {
            tips.style.display = "block";
            tips.innerHTML = "密码应为8-16位！";
            delay();
            return false;
        }
        if(Sdata.psw != Sdata.psw2) {
            tips.style.display = "block";
            tips.innerHTML = "前后两次输入密码不一致！";
            delay();
            return false;
        }
        if(!reg2.test(Sdata.user)) {
            tips.style.display = "block";
            tips.innerHTML = "您输入的姓名格式不正确!";
            delay();
            return false;
        }  
    }
    return true;
}