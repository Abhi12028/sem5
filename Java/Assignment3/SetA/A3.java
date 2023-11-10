import java.util.*;

interface Operation{
	public void area();
	public void volume();
	static final double pi = 3.142;	
}

class cylinder implements Operation{
	int radius,height;
	cylinder(int radius,int height){
		this.radius=radius;
		this.height=height;
	}
	public void area(){
		double areaResult = 2*pi*radius*(radius+height);
		System.out.println("\nVolume of Area:: "+areaResult);	
	}
	public void volume(){
		double volumeResult = pi*radius*radius*height;
		System.out.println("\nVolume of Cylinder:: "+volumeResult+"\n");
	}
}

public class A3{

	public static void main(String[] args){
		cylinder myObj =new cylinder(12,30);
		myObj.area();
		myObj.volume();
	}

}
