import java.util.Scanner;
import java.util.Arrays;

class C1{

	static void display(String[] arr){
		for(String i: arr){
			System.out.printf("\t"+i);
		}
		System.out.println("");
	}	
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		System.out.println("How many countries do you want to enter");
		int size = sc.nextInt();
		String []city = new String[size];
		
		System.out.println("Enter the city names:");
		for(int i=0;i < size;i++)
			city[i] = sc.nextLine();
		System.out.println("Before sorting:");
		display(city);
		Arrays.sort(city,(a, b) -> b.compareTo(a));
		System.out.println("After sorting:");
		display(city);
		 //for (int i = 0; i < size; i++) {
            	//	System.out.println(city[i]);
        	//}
		
		
		
	}
}
