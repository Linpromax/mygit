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
    <title>sign up</title>
    <link rel="stylesheet" href="css/style.css" />
</head>

<body>
<div id="box">
    <div id="sign-up-form">
        <h1>
            Sign up
        </h1>
        <form action="/web/regist" name="signupForm" onsubmit="return processData(this)" method="POST">
            <input type="text" placeholder="Account" class="txt" id="accnt_2" name="usersname"/>
            <input type="text" placeholder="Mobilephone number" class="txt" id="phone" name="telephone"/>
            <input type="password" placeholder="Input password" class="txt" id="psw_1" name="password"/>
            <input type="password" placeholder="Input password again" class="txt" id="psw_2"/>
            <input type="text" placeholder="Email" class="txt" id="email" name="email"/>
            <input type="text" placeholder="Your name" class="txt" id="user" name="name"/>
            <input type="submit" value="sign up" class="btn" />             <!--注册表单-->
        </form>
        <a class="switch" href="log.jsp">Go to login</a>
    </div>
    <div style="clear: both;"></div>
</div>

<script src="js/sendData.js"></script>
</body>
</html>
