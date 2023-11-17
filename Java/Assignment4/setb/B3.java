import java.util.*;
import java.io.*;
import java.lang.*;

class MyDate{
	int dd,mm,yyyy;
	int[] mmCheck31 ={1,3,5,7,8,10,12};
	int[] mmCheck30 ={4,6,9,11};
	MyDate(int dd,int mm,int yyyy){
		this.dd=dd;
		this.mm=mm;
		this.yyyy=yyyy;
	}
	
	int monthCheck(){
		for(int i : mmCheck31){
			if(mm==i){
				return 1;
			}
		}
		for(int i : mmCheck30){
			if(mm==i){
				return 2;
			}
		}
		return 0;
	}
	
	void checkDate(){
		
		if(mm<=12 && dd<=31){
			if((yyyy%400==0 || yyyy%4==0) && yyyy%100!=0 && dd<=29){
				if(mm==2 && dd <= 29){
					System.out.println("Date is Correct:: "+dd+"-"+mm+"-"+yyyy);				
				}
			}
			else if(monthCheck()==1){
				System.out.println("Date is Correct:: "+dd+"-"+mm+"-"+yyyy);
			}
			else if (monthCheck()==2 && dd<=30){
				System.out.println("Date is Correct:: "+dd+"-"+mm+"-"+yyyy);		
			}
			else{
				System.out.println("Date is Invalid");
			}	
		}
		else{
			System.out.println("Date is Invalid");
		}
		
		
	}
	
}



public class B3{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		System.out.print("Date::");
		int dd =sc.nextInt();
		System.out.print("Month::");
		int mm =sc.nextInt();
		System.out.print("Year::");
		int yyyy=sc.nextInt();
		
		MyDate date = new MyDate(dd,mm,yyyy);
		date.checkDate();
		
		
	
	}
}
