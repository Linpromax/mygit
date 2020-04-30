package controller;

import model.DAO;
import model.DbUtil;
import model.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;


public class RegistServlet extends HttpServlet{

    @Override
    protected void doGet(HttpServletRequest req,
                         HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req,
                          HttpServletResponse resp) throws ServletException, IOException {


        /**
         * 接收前台传来的值 账号和密码
         */

        //获取注册用户名
        String usersname=req.getParameter("usersname");
        //获取注册用户密码
        String password=req.getParameter("password");
        String telephone=req.getParameter("telephone");
        String email=req.getParameter("email");
        String name=req.getParameter("name");

        DbUtil db= new DbUtil();
        User user=new User(usersname,password,telephone,email,name);
        DAO dao=new DAO();
        try {
            //数据库链接
            Connection con=db.getCon();
            if(dao.regist(con,user)) {
                resp.sendRedirect("registSuccess.jsp");
            }else {
                resp.sendRedirect("registFail.jsp");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}