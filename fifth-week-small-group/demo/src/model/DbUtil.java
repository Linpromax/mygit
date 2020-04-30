package model;

import java.sql.Connection;
import java.sql.DriverManager;


public class DbUtil {

    /**
     * @DbUtil类的作用 jdbc 的一些简单配置
     * dbUrl
     * <p>
     * dbpassword
     * jdbcName
     */

    private String dbUrl = "jdbc:mysql://localhost:3306/user?serverTimezone=UTC";


    private String dbUsersname = "root";
    private String dbPassword = "13692958402+l";



    private String jdbcName = "com.mysql.cj.jdbc.Driver"; /** 我用com.mysql.jdbc.Driver时出错，百度解决办法是：com.mysql.cj.jdbc.Driver **/

    /**
     * 获取数据库连接
     *
     * @return
     * @throws Exception
     */
    public Connection getCon() throws Exception {
        Class.forName(jdbcName);
        Connection con = DriverManager.getConnection(dbUrl, dbUsersname, dbPassword);
        return con;
    }

    /**
     * 关闭数据库连接
     *
     * @param con
     * @throws Exception
     */
    public void closeCon(Connection con) throws Exception {
        if (con != null) {
            con.close();
        }
    }
}