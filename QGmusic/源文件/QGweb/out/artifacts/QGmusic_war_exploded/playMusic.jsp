<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/5/10
  Time: 17:14
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>音乐播放</title>
    <meta charset="UTF-8" />
    <link rel="stylesheet" href="css/playMusic.css" type="text/css"/>
    <%--页面图标--%>
    <link rel="icon" href="/images/icon.png"/>
</head>

<body>
<%--显示歌名与演唱者--%>
    <h3></h3>
<%--显示歌词--%>
    <div id="box">
        <ul id="play">
        </ul>
    </div>
    <footer>
        <audio src=""  autoplay controls>您的浏览器不支持audio标签！</audio>
    </footer>

    <script src="js/lyricRoll.js"></script>
</body>
</html>