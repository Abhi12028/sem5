import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main{

	static void check(String fname){
		try{
			File newFile =new File(fname);
			Scanner myReader =new Scanner(newFile);
			int line=0,wordCount=0;
			while(myReader.hasNextLine()){
				String data =myReader.nextLine();
				line+=1;
				String[] word=data.split("\\s+");
				wordCount+= word.length;
				
			}
			myReader.close();
			System.out.println("Line: "+line+"\nWords: "+wordCount);
			
		}
		catch(FileNotFoundException e){
			System.out.println("error::File Not Found");
			e.printStackTrace();
			
		}
		
	}
	
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		System.out.print("Enter File Name::");
		String fName= sc.nextLine();
	
		check(fName);
	}
	
}
