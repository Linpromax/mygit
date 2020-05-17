<%--
  Created by IntelliJ IDEA.
  User: Pluto
  Date: 2020/5/7
  Time: 10:29
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <title>QG云音乐</title>
    <meta charset="UTF-8" />
    <link rel="stylesheet" href="css/main.css" type="text/css"/>
    <%--页面图标--%>
    <link rel="icon" href="/images/icon2.png"/>
    <%--链接iconfont--%>
    <link rel="stylesheet" href="http://at.alicdn.com/t/font_1798245_hn2qk3otoxc.css" />  <!--需要联网-->
</head>

<body>
    <header>
        <h1 id="logo">QG云音乐</h1>
    <%--    搜索框--%>
        <div id="search">
            <div>
                <input type="text" value="" placeholder="搜索音乐" id="music"/>
            </div>
            <i class="iconfont icon-magnifier" id="searchMusic"></i>
        </div>
    <%--    登录/注册按钮--%>
        <div id="switch">
            <span>
                <a href="login.jsp" id="login">
                    <i class="iconfont icon-denglu"></i>
                    <span> 登录 </span>
                </a>
            </span>

            <span>
                <a href="regist.jsp" id="regist">
                    <i class="iconfont icon-zhuce"></i>
                    <span> 注册 </span>
                </a>
            </span>
        </div>
    </header>
<%--    轮播图--%>
    <div id="main">
        <div id="container">
            <div class="wrap">
                <img src="/images/album05.jpg" alt="">
                <img src="/images/album01.jpg" alt="">
                <img src="/images/album02.jpg" alt="">
                <img src="/images/album03.jpg" alt="">
                <img src="/images/album04.jpg" alt="">
                <img src="/images/album05.jpg" alt="">
                <img src="/images/album01.jpg" alt="">
            </div>
            <div class="btns">
                <span class="on"></span>
                <span></span>
                <span></span>
                <span></span>
                <span></span>
            </div>
            <span class="arrow arrow_left">&lt;</span>
            <span class="arrow arrow_right">&gt;</span>
        </div>
    </div>
<%--    歌单推荐--%>
    <h3>个性推荐</h3>
    <div id="popular">

        <div>
            <img src="/images/list01.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
        <div>
            <img src="/images/list02.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
        <div>
            <img src="/images/list03.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
        <div>
            <img src="/images/list04.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
        <div>
            <img src="/images/list05.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
        <div>
            <img src="/images/list06.jpg" />
            <i class="iconfont icon-bofang"></i>
        </div>
    </div>
<%--    歌曲分类--%>
    <h3>歌曲分类</h3>
    <div id="category">
        <nav>
            <span>流行</span>
            <span>古风</span>
            <span>电子</span>
            <span>说唱</span>
            <span>民谣</span>
        </nav>
        <hr/>
        <div>
            <div>
                <img src="https://p1.music.126.net/UuKmzOfFymLTGW77VTAFMw==/109951164170448016.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p2.music.126.net/vqfm-EC3EAgX2v3SHikzYg==/109951164173100146.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p1.music.126.net/2uS93Qr4E7Z3txE1qKyAoA==/109951164221434549.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p1.music.126.net/fHNURe3hDFtkR_Zp70lxog==/109951164196001198.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p2.music.126.net/h3Y8LZzp441yADUjDzTTtg==/109951163870769516.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
        </div>
        <div>
            <div>
                <img src="https://p1.music.126.net/eANAaPbJdYhywwLezxjPHg==/109951164599770437.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p2.music.126.net/DR0V4uuPtVlCnRdO6hXViA==/109951164626775500.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p2.music.126.net/ke_3Q-qOj62YkDxh4Oi51Q==/109951164784349480.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p2.music.126.net/FsAKBESx3R5v1LUaTxu58g==/109951164709904271.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
            <div>
                <img src="https://p1.music.126.net/u_gvC2hrCI6xOuJUAmC8TQ==/109951164349965190.jpg" />
                <i class="iconfont icon-bofang"></i>
            </div>
        </div>
        <hr/>
    </div>
<%--    底部栏--%>
    <div id="bottom">
        <span>
            关于QG | About QG | 服务条款 | 用户服务协议 | 隐私政策 | 权利声明 | 广告服务 | 企业招聘 | 客服中心 | 网站导航
        </span>
        <span>
            Copyright © 2001 - 2020 QG. All Rights Reserved.
        </span>
        <span>
            QG公司 版权所有 QG网络文化经营许可证
        </span>
    </div>

<%--    搜索结果展示--%>
    <div id="searchResult">
        <div>
            <i class="iconfont icon-close-cross" id="closeResult"></i>
            <h2>歌曲列表</h2>
            <div id="resultBox"></div>
        </div>
    </div>
<%--    歌单的歌曲列表展示--%>
    <div id="recommend">
        <span><i class="iconfont icon-close-cross"></i></span>
        <div></div>
    </div>


    <script src="js/behavior.js"></script>
    <script src="js/getMusic.js"></script>
    <script src="js/getMusicList.js"></script>
</body>
</html>