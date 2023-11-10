import java.util.*;

abstract class order{
	int id;
	String description;
	abstract void Accept();
	abstract void display();
}

class PurchaseOrder extends order{
	String  customerName;
	Scanner sc = new Scanner(System.in);
	void Accept(){
		System.out.println("************************PurchaseOrder************************");
		System.out.print("Id::");
		this.id=sc.nextInt();
		System.out.print("Description::");
		this.description=sc.next();
		System.out.print("customerName::");
		this.customerName=sc.next();
	}
	void display(){
		System.out.print("Id::"+id);
		System.out.print("\tDescription::"+description);
		System.out.println("\tcustomerName::"+customerName);
	}
}

class salesOrder extends order{
	String  vendorName;
	Scanner sc = new Scanner(System.in);
	void Accept(){
		System.out.println("************************salesOrder************************");
		System.out.print("Id::");
		this.id=sc.nextInt();
		System.out.print("Description::");
		this.description=sc.next();
		System.out.print("vendorName::");
		this.vendorName=sc.next();
	}
	void display(){
		System.out.print("Id::"+id);
		System.out.print("\tDescription::"+description);
		System.out.println("\tvendorName::"+vendorName);
	}
}

public class B1{
	public static void main(String[] args){
		PurchaseOrder[] porder=new PurchaseOrder[1];
		salesOrder[] sorder=new salesOrder[1];
		for(int i=0;i<1;i++){
			porder[i]=new PurchaseOrder();
			porder[i].Accept();
			
		}
		for(int i=0;i<1;i++){
			sorder[i]=new salesOrder();
			sorder[i].Accept();
		}
		for(int i=0;i<1;i++){
			porder[i].display();
			sorder[i].display();
		}
		
	}	

}
