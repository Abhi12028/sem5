import java.util.*;
abstract class staff{
	protected int id;
	protected String name;
	staff(int id,String name){
		this.id=id;
		this.name=name;
	}
}

class officeStaff extends staff{
	String department;
	officeStaff(int id , String name,String department){
		super(id,name);
		this.department=department;
	}
}

public class A2{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("How many staff member:");
		int num=sc.nextInt();
	
		int j,id;
		String name , department;
	
		officeStaff[] member=new officeStaff[num];
		for(int i=0;i<num;i++){
			j=i+1;
			System.out.println("Enter details of "+j+"member");
			System.out.print("id:");
			id=sc.nextInt();
			
			System.out.print("\nname:");
			name=sc.next();
		
			System.out.print("\ndepartment:");
			department=sc.next();
			member[i] =new officeStaff(id,name,department);
		}
		for(int i=0;i<num;i++){
			System.out.println("Name::"+member[i].name+"\tID::"+member[i].id+"\tDeoartment::"+member[i].department);
		}
	}
	
}
