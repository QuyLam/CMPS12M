//---------------------------------------------------------------------------
// Quy Lam
// qlam
// 12M
// 3/30/16
//---------------------------------------------------------------------------
// HelloUser2.java
// Prints out "Hello, world!" phrase and user id.
//---------------------------------------------------------------------------
class HelloUser2{
    public static void main( String [] args){
	String userName = System.getProperty("user.name");

	System.out.println("Hello, world!");
	System.out.println("User name is "+userName);
    }
}
