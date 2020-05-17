package Controller.Servlet;

import Model.DAO.UserDAO;
import Model.DTO.UserDTO;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/UserLoginServlet") //该注解用于设置虚拟路径
public class UserLoginServlet extends HttpServlet {
	//统一为post
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//接收账号和密码
		request.setCharacterEncoding("UTF-8");  //避免编码不同
		String accout = request.getParameter("userAccout");  //获取页面传来的参数
		String password = request.getParameter("userPassword");

		//调用UserDAO中checkLogin方法
		UserDAO uDao = new UserDAO();
		UserDTO user = uDao.checkLogin(accout, password);

		if (user == null) {  //登录失败
			response.sendRedirect("login.jsp?error=yes"); //转到登录页面并传送参数
		}else {  //登录成功
			//请求转发到主页面2，返回用户其他信息
			request.getRequestDispatcher("main2.jsp?accout=" + user.getUserAccout() +
					"&name=" + user.getUserName() + "&tel=" + user.getUserTel()).forward(request, response);

		}
	}
	
}
