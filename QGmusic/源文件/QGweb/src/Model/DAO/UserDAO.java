package Model.DAO;

import Model.DTO.UserDTO;
import Model.Utils.DBManager;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;


/**
 * 此类用于对于数据库表 qgusers 的操作
 *
 */
public class UserDAO {
    private Connection conn;
    private PreparedStatement ps;
    private ResultSet rs;

    /**
     * 添加用户信息
     *
     * @param user 需要添加到数据库的用户信息
     * @return 如果添加成功返回true,失败则返回false
     */
    public boolean insertUser(UserDTO user) {
        boolean flag = false;
        try {
            conn = DBManager.getConn();
            String sql = "insert into qgusers values(null,?,?,?,?)";
            ps = conn.prepareStatement(sql);
            // 给？赋值
            ps.setString(1, user.getUserAccout());
            ps.setString(2, user.getUserPassword());
            ps.setString(3, user.getUserName());
            ps.setString(4, user.getUserTel());
            // 执行SQL
            int i = ps.executeUpdate();
            // 处理结果
            flag = i > 0 ? true : false;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBManager.close(null, ps, conn);
        }
        return flag;
    }


    /**
     * 通过用户名和密码查询用户信息是否存在
     *
     * @param accout
     * @param password
     * @return UserDTO对象
     */
    public UserDTO checkLogin(String accout, String password) {
        UserDTO user = null;
        try {
            conn = DBManager.getConn();
            String sql = "select * from qgusers where userAccout = ? and userPassword = ?";
            ps = conn.prepareStatement(sql);
            ps.setString(1, accout);
            ps.setString(2, password);
            rs = ps.executeQuery();

            while (rs.next()) {
                user = new UserDTO(rs.getInt("userId"),
                                rs.getString("userAccout"),
                                rs.getString("userPassword"),
                                rs.getString("userName"),
                                rs.getString("userTel"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBManager.close(rs, ps, conn);
        }

        return user;
    }
}
