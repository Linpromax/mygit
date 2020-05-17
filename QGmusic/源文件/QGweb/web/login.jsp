<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/5/10
  Time: 11:47
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
    <meta charset="utf-8" />
    <link href="css/loginOrRegist.css" rel="stylesheet" />
    <%--页面图标--%>
    <link rel="icon" href="/images/icon2.png"/>
    <%--链接iconfont--%>
    <link rel="stylesheet" href="http://at.alicdn.com/t/font_1798245_hn2qk3otoxc.css" />
</head>

<body>
<%--    显示提示信息--%>
    <h4 class="tips"></h4>
<%--    登录模块--%>
    <div id="loginBox">
        <form action="UserLoginServlet" name="loginForm" onsubmit="return checkForm(this)" method="POST">
            <a href="main.jsp"><i class="iconfont icon-fanhuishangyiye"></i></a>
            <input type="text" placeholder="账号"  name="userAccout" class="txt acct" />
            <input type="password" placeholder="密码" name="userPassword" class="txt psw" />
            <input type="submit" value="登录" class="btn" />
        </form>
    </div>
<%--    检查表单输入的js--%>
    <script src="js/checkForm.js"></script>

    <script>
        //取出servlet传回来的参数error并与yes比较
        var Error = '<%=request.getParameter("error")%>';

        if(Error =='yes') {
            var tips = document.getElementsByClassName("tips")[0];
            tips.style.display = "block";
            tips.innerHTML = "登录失败， 账号或密码错误！";  //显示失败信息
            setTimeout(function () {  //3秒后提示自动消失
                tips.style.display = "none";
                tips.innerHTML = "";
            }, 3000);
        }
    </script>
</body>
</html>
