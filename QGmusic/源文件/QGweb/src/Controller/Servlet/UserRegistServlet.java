package Controller.Servlet;

import Model.DAO.UserDAO;
import Model.DTO.UserDTO;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet("/UserRegistServlet")
public class UserRegistServlet extends HttpServlet {

	protected void doGet(HttpServletRequest req, HttpServletResponse response) throws ServletException, IOException {
		doPost(req, response);
	}

	protected void doPost(HttpServletRequest req, HttpServletResponse response) throws ServletException, IOException {
		req.setCharacterEncoding("UTF-8");

		try {
			String userAccout = req.getParameter("userAccout");
			String userPassword = req.getParameter("userPassword");
			String userName = req.getParameter("userName");
			String userTel = req.getParameter("userTel");
			UserDTO user = new UserDTO(0,userAccout,userPassword,userName,userTel);
			//调用UserDAO中的inertUser方法完成用户注册信息的保存
			UserDAO uDao = new UserDAO();
			boolean flag = uDao.insertUser(user);
			System.out.println(flag);
			//根据保存结果进行跳转
			if (!flag) {
				response.sendRedirect("main.jsp?error2=yes");
			} else{
				req.getRequestDispatcher("main2.jsp?accout=" + user.getUserAccout() +
						"&name=" + user.getUserName() + "&tel=" + user.getUserTel()).forward(req, response);  //请求转发
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
