import java.util.Scanner;
import java.util.Arrays;

class C3{

	static void displayTable(int num){
		for(int i=1;i<=10;i++)
			print("num*"+i+"::"+num*i);
		System.out.println("*********************");
	}	
	
	public static void main(String args[]){
		
		for(int i=1;i<=15;i++){
			displayTable(i);
		}
		System.out.println("Done");
		
		
	}
}

