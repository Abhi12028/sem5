import java.util.Scanner;
import java.util.Arrays;

class C2{

	static void display(int[][] arr){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				System.out.print(arr[i][j]+"  ");
			System.out.println("");
		}
		System.out.println("");
	}
	
	
	
	public static void main(String args[]){
		int [][]arr = {{1,2,3,4},{5,6,7,8},{8,9,5,3},{4,8,2,0}};
		
		display(arr);
		Scanner sc = new Scanner(System.in);	
		
		while(true){
			System.out.println("******************************\n1.Sum of diagonal elements\n2. Sum of upper diagonal element\n3.Sum of lower diagonal element\n4.Exit\n\n Enter choice::");
			int choice = sc.nextInt();
			int sum=0;
			switch(choice){
				case 1:
					for(int i=0;i<4;i++)
						sum +=arr[i][i];
					System.out.println("Sum of diagonal elements is ::"+sum);
					break;
				case 2:
					for(int i=0;i<4-1;i++){
						sum +=arr[i][i+1];
						}
					System.out.println("Sum of Upper diagonal elements is ::"+sum);
					break;
				case 3:
					for(int i=1;i<4;i++){
							sum +=arr[i][i-1];
						}
					System.out.println("Sum of Lower diagonal elements is ::"+sum);
					break;
				case 4:
					break;
					
					
			}
			if(choice==4)
				break;
			
		}
	}
}
