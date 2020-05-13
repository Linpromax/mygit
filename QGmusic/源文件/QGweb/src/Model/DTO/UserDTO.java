package Model.DTO;
/**
 * UserDTO类用于存放一个用户信息
 *
 *
 */
public class UserDTO {
	private int userId;//用户编号
	private String userAccout;//用户账号
	private String userPassword;//用户密码
	private String userName;//用户姓名
	private String userTel;//用户手机号码

	
	public UserDTO() {

	}

	public UserDTO(int userId, String userAccout, String userPassword, String userName,
				   String userTel) {
		super();
		this.userId = userId;
		this.userAccout = userAccout;
		this.userPassword = userPassword;
		this.userName = userName;
		this.userTel = userTel;

	}//设置构造方法

	public int getUserId() {
		return userId;
	}

	public void setUserId(int userId) {
		this.userId = userId;
	}

	public String getUserAccout() { return userAccout; }

	public void setUserAccout(String userAccout) {
		this.userAccout = userAccout;
	}

	public String getUserPassword() {
		return userPassword;
	}

	public void setUserPassword(String userPassword) {
		this.userPassword = userPassword;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getUserTel() { return userTel; }

	public void setUserTel(String userTel) {
		this.userTel = userTel;
	}

	@Override
	public String toString() {
		return "UserDTO [userId=" + userId + ", userAccout=" + userAccout + ", userPassword=" + userPassword + ", userName="
				+ userName + ", userTel=" + userTel + "]";
	}
	
}
