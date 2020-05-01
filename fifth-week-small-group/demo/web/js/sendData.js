

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

function processData(thisform){
    var reg1 = /^\d{11}$/;
    // var reg2 = /^\d{6}$/;
    var reg3 = /^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/;
    var reg4 = /^([\u4e00-\u9fa5\·]{2,20}|[a-zA-Z\.\s]{2,20})$/;
    if(!isNotEmpty(thisform)){
        return false;
    }
    if("loginForm" === thisform.name)
    {
        let Ldata = {
            accout1: document.getElementById("accnt_1").value,
            psw: document.getElementById("psw").value
        };
        if(Ldata.accout1.length < 8 || Ldata.accout1.length > 16)
        {
            alert("用户名应为8-16位！");
            return false;
        }
        if(Ldata.psw.length < 8 || Ldata.psw.length > 16)
        {
            alert("密码应为8-16位！");
            return false;
        }

    }
    else
    {
        let Sdata = {
            accout2: document.getElementById("accnt_2").value,
            phone: document.getElementById("phone").value,
            psw1: document.getElementById("psw_1").value,
            psw2: document.getElementById("psw_2").value,
            email: document.getElementById("email").value,
            user: document.getElementById("user").value
        };
        if(Sdata.accout2.length < 8 || Sdata.accout2.length > 16)
        {
            alert("用户名应为8-16位！");
            return false;
        }
        if (!reg1.test(Sdata.phone)) {
            alert("请输入正确11位数字手机号码！");
            return false;
        }
        if(Sdata.psw1.length < 8 || Sdata.psw1.length > 16)
        {
            alert("密码应为8-16位！");
            return false;
        }
        if(Sdata.psw1 != Sdata.psw2)
        {
            alert("前后两次输入密码不一致！");
            return false;
        }
        if(!reg3.test(Sdata.email)){
            alert("您输入的email格式不正确!");
            return false;
        }
        if(!reg4.test(Sdata.user)){
            alert("您输入的姓名格式不正确!");
            return false;
        }
    }
    return true;
}