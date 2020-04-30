package model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;



public class DAO {
    /**
     * login(Connection con,User user) 登录验证
     * (Connection con,User user)注册功能

     */
    public User login(Connection con,User user) throws Exception{
        User resultUser=null;
        String sql="select * from users where usersname=? and password=?";
        PreparedStatement pst=con.prepareStatement(sql);
        pst.setString(1, user.getUsersname());
        pst.setString(2, user.getPassword());
        try (ResultSet rs = pst.executeQuery()) {
            if (rs.next()) {
                resultUser = new User();
                resultUser.setUsersname(rs.getString("usersname"));
                resultUser.setPassword(rs.getString("password"));
            }
        }
        return resultUser;
    }

    //注册功能
    public boolean regist(Connection con,User user) throws Exception{
        boolean flag=false;
        String sql="INSERT INTO users(usersname,password,telephone,email,name)VALUES(?,?,?,?,?)";
        PreparedStatement pst = con.prepareStatement(sql);
        pst.setString(1, user.getUsersname());
        pst.setString(2, user.getPassword());
        pst.setString(3, user.getTelephone());
        pst.setString(4, user.getEmail());
        pst.setString(5, user.getName());

        if (pst.executeUpdate() > 0) {
            flag = true;
        }
        return flag;
    }

}