let serverUrl = 'http://recruit.qgailab.com/';

function sendData(thisform){
    if("loginForm" === thisform.name){
        let ldata = {
            username: document.getElementById("accnt_1").value,
            password: document.getElementById("psw").value   
        };
        let Lhttp;

        if(window.XMLHttpRequest){  
            Lhttp = new XMLHttpRequest(); 
        }else{
            Lttp = new ActiveXObject("Microsoft.XMLHTTP");   //针对IE5,IE6
        }
        Lhttp.open("POST",serverUrl + "ajax/login",true);
        Lhttp.setRequestHeader("Content-type","application/json");
        Lhttp.send(JSON.stringify(ldata));

        Lhttp.onreadystatechange = function(){
            if(Lhttp.readyState === 4 && Lhttp.status === 200){
                let Lresult = JSON.parse(Lhttp.responseText)
                if (Lresult.code === "1"){
                    alert(Lresult.message);
                    return true;
                }else{
                    alert(Lresult.message);
                }                 
            }
        }
        return false;
    }
    else if("signupForm" === thisform.name){
        let sdata = {
            username: document.getElementById("accnt_2").value,
            password: document.getElementById("psw_1").value,
            phone: document.getElementById("phone").value,
            email: document.getElementById("email").value,
            name: document.getElementById("user").value
        };
        let Shttp;

        if(window.XMLHttpRequest){  
            Shttp = new XMLHttpRequest(); 
        }else{
            Sttp = new ActiveXObject("Microsoft.XMLHTTP");   //针对IE5,IE6
        }
        Shttp.open("POST",serverUrl + "ajax/register", true);
        Shttp.setRequestHeader("Content-type","application/json");
        Shttp.send(JSON.stringify(sdata));

        Shttp.onreadystatechange = function(){
            if (Shttp.readyState === 4 && Shttp.status === 200){
                let Sresult = JSON.parse(Shttp.responseText);
                if(Sresult.code === "1"){
                    alert(Sresult.message);
                    return true;
                }
                else{
                    alert(Sresult.message);
                }
            }
        }
        return false;
    }
}

function checkUserName(){
    let data = document.getElementById("accnt_1").value;
    let http;

    if(window.XMLHttpRequest){  
        http = new XMLHttpRequest(); 
    }else{
        http = new ActiveXObject("Microsoft.XMLHTTP");   //针对IE5,IE6
    }
    http.open("GET",serverUrl + "ajax/find?username=" + data, true);
    http.send(null);
    
    http.onreadystatechange = function(){
        if(http.readyState === 4  && http.status === 200){ 
            let result = JSON.parse(http.responseText);
            if(result.code === "1"){
                alert(result.message);
            }
            else{
                alert(result.message);
            }
        }
    }
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

function processData(thisform){
    var reg1 = /^\d{11}$/;
    // var reg2 = /^\d{6}$/;   
    var reg3 = /^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/; 
    var reg4 = /^([\u4e00-\u9fa5\·]{2,20}|[a-zA-Z\.\s]{2,20})$/;
    if(!isNotEmpty(thisform)){
        return false;
    }
    if("loginForm" == thisform.name)
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
        checkUserName();
    }
    else if("signupForm" == thisform.name)
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
    return sendData(thisform);
}