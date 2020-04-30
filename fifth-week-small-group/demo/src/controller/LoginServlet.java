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


public class LoginServlet extends HttpServlet{
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
        String usersname=req.getParameter("usersname");

        String password=req.getParameter("password");

        DbUtil db= new DbUtil();
        User user=new User(usersname,password);
        DAO dao=new DAO();
        try {
            //数据库连接
            Connection con=db.getCon();
            if(dao.login(con, user)!=null) {
                resp.sendRedirect("loginSuccess.jsp");
            }else {
                resp.sendRedirect("loginFail.jsp");
            }
        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}