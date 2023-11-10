import java.util.*;

class employee{
	int id,salary;
	String name , deptname;
	public static int count =0;
	
	employee(){
		
		this.id = 000;
		this.salary=10000;
		this.name="abc";
		this.deptname= "IT";
		count=count+1;
		
	}	
}

public class A1{
	
	public static void main(String args[]){
		employee abhi = new employee();
		employee rahul = new employee();
		employee ritu = new employee();
		
		abhi.name = "Abhishek";
		abhi.id=123;
		abhi.salary=100000;
		abhi.deptname="cloud";
		
		System.out.println(abhi.name +"  "+abhi.id);
		System.out.println("Count is ::"+ employee.count);
		
		
	}
}
