<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/4/26
  Time: 12:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="utf-8" %>
<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <title>login</title>
    <link rel="stylesheet" href="css/style.css" />
</head>

<body>
<div id="box2">
    <div id="login-form">
        <h1>
            Login
        </h1>
        <form action="/web/login" name="loginForm" onsubmit="return processData(this)" method="POST">
            <input type="text" placeholder="Account" class="txt" id="accnt_1" name="usersname"/>
            <input type="password" placeholder="Password" class="txt" id="psw" name="password"/>
            <input type="submit" value="Login" class="btn" />
        </form>
        <a class="switch" href="reg.jsp">Go to sign up</a>
    </div>
    <div style="clear: both;"></div>
</div>

<script src="js/sendData.js"></script>
</body>
</html>
