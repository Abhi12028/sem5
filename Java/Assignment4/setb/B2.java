import java.util.*;
import java.io.*;
import java.lang.*;

class email{
	String userName;
	String passwd;
	email(){
		userName = "Monkeyman";
		passwd="1234";
	}
	email(String userName , String passwd){
		this.userName =userName;
		this.passwd=passwd;
	}
}

class invalidUserException extends Exception{
	invalidUserException(){
		System.out.println("invalidUserException");
	}
}

public class B2{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		System.out.print("Username::");
		String userName =sc.next();
		System.out.println("\nPassword::");
		String passwd =sc.next();
		
		email newEmail = new email(userName,passwd);
		System.out.println("********************Login********************");
		
		System.out.print("Username::");
		userName =sc.next();
		System.out.println("\nPassword::");
		 passwd =sc.next();
		
		try{
			if(userName == newEmail.userName && passwd == newEmail.passwd){
				System.out.print("Password Matched pls enter");
			}
		}
		catch(Exception e){
			System.out.print("invalidUserException");
			
		}
	
	}
}
