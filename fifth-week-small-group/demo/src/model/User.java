package model;

public class User {

    private static String usersname;
    private String password;
    private String telephone;
    private String email;
    private String name;

    public User() {}

    public User(String usersname, String password) {
        this.usersname=usersname;
        this.password=password;
    }

    public User(String usersname, String password, String telephone, String email, String name) {
        this.usersname=usersname;
        this.password=password;
        this.telephone=telephone;
        this.email=email;
        this.name=name;
    }

    public static String getUsersname() {
        return usersname;
    }
    public void setUsersname(String usersname) {
        this.usersname = usersname;
    }
    public String getPassword() { return this.password; }
    public void setPassword(String password) {
        this.password = password;
    }
    public String getTelephone() {
        return this.telephone;
    }
    public void setTelephone(String telephone) { this.telephone = telephone; }
    public String getEmail() { return this.email; }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }

}
