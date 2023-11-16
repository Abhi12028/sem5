import java.util.*;

class patient{
	static String patientName;
	static int patientAge,patientOxyLevel,patientHRCTReport;
}

public class A1{
	public static void main(String[] args){
		patient p1 = new patient();
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter patient name:");
		patient.patientName = sc.nextLine();
		System.out.println("Enter patient Age:");
		patient.patientAge = sc.nextInt();
		System.out.println("Enter patient Oxygen Level:");
		patient.patientOxyLevel = sc.nextInt();
		System.out.println("Enter patient HRCT report:");
		patient.patientHRCTReport = sc.nextInt();
	
		if(patient.patientOxyLevel < 95 && patient.patientHRCTReport > 10){
			throw new ArithmeticException("Patient is covid (+) and need to hospitalize");
		}
		else{
			System.out.println("*****************************************");
			System.out.println("Name: "+patient.patientName);
			System.out.println("patient Age: "+patient.patientAge);
			System.out.println("Oxygen Level: "+patient.patientOxyLevel);
			System.out.println("HRCT report: "+patient.patientHRCTReport);
		}
	}
}
