import java.util.*;

class A4{
	
	static String capitalname(String name){
		String firstChar = name.substring(0,1);
		String restChar = name.substring(1);
		firstChar = firstChar.toUpperCase();
		name = firstChar + restChar;
		return name;
	}
	
	public static void main(String args[]){
		String first, middle , last ;
		Scanner sc = new Scanner(System.in);
	
		System.out.println("Enter First name:");
		first = sc.nextLine();
		System.out.println("Enter Middle name:");
		middle = sc.nextLine();
		System.out.println("Enter Last name:");
		last = sc.nextLine();
		
		System.out.println("***************************");
		System.out.println("First name:"+first);
		System.out.println("Middle name:"+capitalname(middle));
		System.out.println("Last name:"+last);
	}
	
}


