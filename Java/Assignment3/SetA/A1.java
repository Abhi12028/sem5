import java.util.*;

class continent{
	String continentName;
	continent(String continentName){
		this.continentName= continentName;
	}
}

class country extends continent{
	String country;
	country(String country , String continentName){
		super(continentName);
		this.country= country;
	}
}

class state extends country{
	String stateName;
	state(String stateName ,String country , String continentName){
		super(country,continentName);
		this.stateName= stateName;
	}
}

class A1{
	public static void main(String[] args){
		String continentName = "Asia";
		String country = "Bharat";
		String stateName = "Maharastra";
		String place = "Warje Malwadi";
		
		state city = new state(stateName , country , continentName);
		
		System.out.println("\nPlace: "+place+"\tState: "+city.stateName+"\tCountry:  "+city.country+"\tContinent: "+city.continentName+"\n");
		
	}
}
