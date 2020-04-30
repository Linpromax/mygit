<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/4/28
  Time: 14:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
            <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

            <title>欢迎来到我的网站</title>
            <style type="text/css" media="screen">
                .center{
                    position:absolute;
                    width: 200px;
                    height: 120px;
                    left: 50%;
                    top: 50%;
                    margin: -60px 0px 0px -60px;

                }
            </style>
</head>

<body style="background-color: skyblue;
                 background-size:cover;">
<div class="center">
    <h3 style="color:red">这是首页，欢迎光临！</h3>

    <tr>
        <a href="log.jsp" target="_self"><li>用户登录</li></a>
        <a href="reg.jsp" target="_self" class="right40"><li>新用户注册</li></a>
    </tr>
</div>

</body>
<html>