import java.util.*;
import java.io.*;
import java.lang.*;



public class A2{
	public static void main(String[] args){
		StringBuilder readLine = new StringBuilder();
		try{
			File newFile = new File("new.dat");//do makke a file
			Scanner sc = new Scanner(newFile);
			while (sc.hasNextLine()){
        			String data = sc.nextLine();
        			data=data.toUpperCase();
        			//System.out.println(data);
        			readLine.append(data);
        			readLine.reverse(); //this StringBUilder append and reverse function and the import files should be presnt
        			System.out.println(readLine);
        			readLine.setLength(0);
			}
		}
		catch(FileNotFoundException e){
			System.out.println("Error occuerd while handling File::");
			e.printStackTrace();
			
		}
		
		
	}
}
