
function isNotEmpty(thisform) {
    var x = thisform.getElementsByTagName("input");
    var count = thisform.getElementsByTagName("input").length;
    for(var i = 0; i < count; i++) {
        if(x[i].value == null || x[i].value == "") {
            alert("请填写完整！");
            return false;
        }
    }
    return true;
}

function checkForm(thisform) {
    var reg1 = /^\d{11}$/;
    var reg2 = /^([\u4e00-\u9fa5\·]{2,20}|[a-zA-Z\.\s]{2,20})$/;
    if(!isNotEmpty(thisform)) {
        return false;
    }
    if("loginForm" === thisform.name) {
        let Ldata = {
            accout: thisform.getElementsByClassName("acct")[0].value,
            psw: thisform.getElementsByClassName("psw")[0].value
        };
        if(Ldata.accout.length < 8 || Ldata.accout.length > 16) {
            alert("用户名应为8-16位！");
            return false;
        }
        if(Ldata.psw.length < 8 || Ldata.psw.length > 16) {
            alert("密码应为8-16位！");
            return false;
        } 
    } else if("registForm" == thisform.name) {
        let Sdata = {
            accout: thisform.getElementsByClassName("acct")[0].value,
            phone: thisform.getElementsByClassName("tel")[0].value,
            psw: thisform.getElementsByClassName("psw")[0].value,
            psw2: thisform.getElementsByClassName("psw2")[0].value,
            user: thisform.getElementsByClassName("name")[0].value
        };
        if(Sdata.accout.length < 8 || Sdata.accout.length > 16) {
            alert("用户名应为8-16位！");
            return false;
        }
        if (!reg1.test(Sdata.phone)) {
            alert("请输入正确11位数字手机号码！");
            return false;
        }
        if(Sdata.psw.length < 8 || Sdata.psw.length > 16) {
            alert("密码应为8-16位！");
            return false;
        }
        if(Sdata.psw != Sdata.psw2) {
            alert("前后两次输入密码不一致！");
            return false;
        }
        if(!reg2.test(Sdata.user)) {    
            alert("您输入的姓名格式不正确!");   
            return false;
        }  
    }
    return true;
}