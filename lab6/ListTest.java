//---------------------------------------------------------------------------
// Quy Lam
// qlam
// 12m
// 05/25/16    
//-----------------------------------------------------------------------------
// ListTest.java
// Test file for List.java
//-----------------------------------------------------------------------------

public class ListTest{
    public static void main(String[] args){
	List<String> A = new List<String>();
	List<Double> B = new List<Double>();
	String get;
 

	System.out.print("Size = ");
	System.out.println(A.size());
	System.out.print("isEmpty = ");
	System.out.println(A.isEmpty());

	A.add(1, "new");
	B.add(1, 10.0);
	A.add(2, "one");
	A.add(3, "in");
	A.add(4, "out");
	B.add(2, -10.0);


	System.out.println("A: "+A);
	System.out.print("Size A = ");
	System.out.println(A.size());

	System.out.println("A.equals(B) is "+A.equals(B));
	System.out.println("B.equals(A) is "+B.equals(A));
	
	System.out.print("Get 4 = ");
	get = A.get(4);
	System.out.println(get);

	A.remove(1);
	System.out.println("Remove 1");

	A.remove(3);
	System.out.println("Remove 3");
	System.out.println("A: "+A);

	B.remove(2);
	System.out.println("Remove 2");
	System.out.println("B: " +B);


	System.out.println("A: "+A);
	System.out.print("Size A = ");
	System.out.println(A.size());
	
	System.out.println("B: "+B);
	System.out.print("Size B = ");
	System.out.println(B.size());

	A.removeAll();
	System.out.println("A: "+A);
	System.out.print("Size A = ");
	System.out.println(A.size());
	


    }
}
