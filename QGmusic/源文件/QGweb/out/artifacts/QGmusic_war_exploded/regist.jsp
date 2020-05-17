<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/5/10
  Time: 14:05
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册</title>
    <meta charset="utf-8" />
    <link href="css/loginOrRegist.css" rel="stylesheet" />
    <%--页面图标--%>
    <link rel="icon" href="/images/icon2.png"/>
    <%--引入iconfont--%>
    <link rel="stylesheet" href="http://at.alicdn.com/t/font_1798245_hn2qk3otoxc.css" />
</head>

<body>
<%--    显示提示信息--%>
    <h4 class="tips"></h4>
    <div id="registBox">
        <form action="UserRegistServlet" name="registForm" onsubmit="return checkForm(this)" method="POST">
            <a href="main.jsp"><i class="iconfont icon-fanhuishangyiye"></i></a>
            <input type="text" placeholder="账号" name="userAccout" class="txt acct" />
            <input type="password" placeholder="密码" name="userPassword" class="txt psw" />
            <input type="password" placeholder="确认密码" class="txt psw2" />
            <input type="text" placeholder="姓名" name="userName" class="txt name" />
            <input type="text" placeholder="手机号码" name="userTel" class="txt tel" />
            <input type="submit" value="注册并登录" class="btn" />             <!--注册表单-->
        </form>
    </div>
    <script src="js/checkForm.js"></script>

    <script>
        //取出servlet传回来的参数error2并与yes比较
        var Error2 = '<%=request.getParameter("error2")%>';

        if(Error2 =='yes') {
            var tips = document.getElementsByClassName("tips")[0];
            tips.style.display = "block";
            tips.innerHTML = "注册失败， 账号已存在！";
            setTimeout(function () {
                tips.style.display = "none";
                tips.innerHTML = "";
            }, 3000);
        }
    </script>
</body>
</html>