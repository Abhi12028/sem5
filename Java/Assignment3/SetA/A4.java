import java.util.*;

interface Operation{
	public void cubeOfNumber();	
}

class cube implements Operation{
	int num;
	cube(int num){
		this.num=num;
	}
	public void cubeOfNumber(){
		int result = num*num*num;
		System.out.println("Cube of Number"+ this.num+ "is::"+result);	
	}
}

public class A4{

	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		int num=1;//this extra work that i have done nothing more ...date 2-12-2023
		while(num!=0){
			System.out.println("\nEnter number::");
			num=sc.nextInt();
			cube myObj =new cube(num);
			myObj.cubeOfNumber();
		}
			
	}

}
