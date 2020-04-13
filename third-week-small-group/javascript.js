
function showsignup(){   
      var sign = document.getElementById("sign-up-form");
      var login = document.getElementById("login-form");
      sign.style.display="block";
      login.style.display="none";
}

function showlogin(){ 
      var sign = document.getElementById("sign-up-form");
      var login = document.getElementById("login-form");
      login.style.display="block";
      sign.style.display="none";
}

function isNotEmpty(thisform)
{
    var x = thisform.getElementsByTagName("input");
    var i, count = thisform.getElementsByTagName("input").length;
    for(i = 0; i < count; i++)
    {
        if(x[i].value == null || x[i].value == "")
        {
            alert("请填写完整！");
            return false;
        }
    }
    return true;
}

function checkForm(thisform){
    var reg1 = /^\d{11}$/;
    var reg2 = /^\d{6}$/;    
    if(!isNotEmpty(thisform)){
        return false;
    }
    if("loginForm" == thisform.name)
    { 
        let Ldata = {
            accout: document.getElementById("accnt").value,
            psw: document.getElementById("psw").value
        };
        if(Ldata.psw.length < 6)
        {
            alert("密码应不少于6位！");
            return false;
        }
       
        if(!reg1.test(Ldata.accout))
        {
            alert("请输入11位数字有效账号！");
            return false;
        } 
        alert("登录成功！");
    }
    else if("signupForm" == thisform.name)
    {
        let Sdata = {
            phone: document.getElementById("phone").value,
            code: document.getElementById("code").value,
            psw1: document.getElementById("psw1").value,
            psw2: document.getElementById("psw2").value
        };
        if (!reg1.test(Sdata.phone)) {
            alert("请输入正确11位数字手机号码！");
            return false;
        }
        if(!reg2.test(Sdata.code))
        {
            alert("验证码应为6位数字！");
            return false;
        }
        if(Sdata.psw1.length < 6)
        {
            alert("密码应不少于6位！");
            return false;
        }
        if(Sdata.psw1 != Sdata.psw2)
        {
            alert("前后两次输入密码不一致！");
            return false;
        }
        alert("注册成功！前往登录。");
    }
}
