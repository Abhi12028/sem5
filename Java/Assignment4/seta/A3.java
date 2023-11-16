import java.util.*;
import java.io.*;
import java.lang.*;



public class A3{
	public static void main(String[] args){
	
		String file1,file2;
		//StringBuilder readLine = new StringBuilder();
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter first file name::");
		file1 = scan.next();
		System.out.println("Enter second file name::");
		file2 = scan.next();
		
		int index=file1.length()-1;
		System.out.println("Index::"+index);
		
		/*if(getCharFromString(file1,file1.length()-1)=="\n"){
			System.out.println("changing...");
			file1.charAt(file1.length()-1)="\0";
			file2.charAt(file2.length()-1)="\0";
		}*/
		
		try{
			FileReader File1 = new FileReader(file1);
			FileWriter File2 =new FileWriter(file2,true);
			
			Scanner sc = new Scanner(File1);
			
			while (sc.hasNextLine()){
        			String data = sc.nextLine();
        			File2.write(data);
        			File2.write("\n");
        			
			}
			File2.write("End of file");
        		File2.close();
			
		}
		catch(IOException e){
			System.out.println("Error occuerd while handling File::");
			e.printStackTrace();
			
		}
		
		
	}
}
