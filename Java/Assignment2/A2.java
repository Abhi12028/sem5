import java.util.*;

class student{
	int rollno;
	float percent;
	String name;
	
	student(int rollno , float percent,String name){
		this.rollno=rollno;
		this.name=name;
		this.percent=percent;
		
	}
	
	void display(){
		System.out.println("Name: "+name+"  Rollno : "+rollno+"  Percentage: "+percent);
	}
        
         static void sortStudent(student[] arr_stud){
        	Arrays.sort(arr_stud, (a,b) -> Double.compare(b.percent,a.percent));
        }
        
         static void arrdisplay(student[] arr_stud){
        	for (student stud : arr_stud) 
            		stud.display();
        }
}

public class A2{
	
	public static void main(String args[]){
			
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of student:");
		int num = sc.nextInt();
		int i=0;
		
		student[] arr_stud = new student[num];
		
		while(i<num){
			System.out.println("##########################\nEnter student name:");
			String name = sc.next();
			
			System.out.println("Enter student roll no:");
			int rollno = sc.nextInt();
			
			System.out.println("Enter student percentage:");
			float percent = sc.nextFloat();
			
			arr_stud[i]= new student(rollno ,percent, name);
			i++;
			
			
		}
		student.arrdisplay(arr_stud);
		student.sortStudent(arr_stud);
		System.out.println("*****************************\n After sort:");
		student.arrdisplay( arr_stud);
			
	}

}
