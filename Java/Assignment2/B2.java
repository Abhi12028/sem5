import java.util.*;

class cricketPlayer{
	int  innings, notouts, totalruns;
	double batAvg;
	String name;
	
	cricketPlayer(String name, int innings, int notouts, int totalruns){
		this.name=name;
		this.innings = innings;
		this.notouts = notouts;
		this.totalruns = totalruns;
		
	}
	
	public static void batingAverage(cricketPlayer[] players){
		int outs;
		for(int i=0 ; i<players.length ; i++){
			outs = players[i].innings-players[i].notouts;
			players[i].batAvg = (players[i].totalruns/outs); 
		}
		
	}
}

public class B2{

	public static void main(String args[]){
		
		System.out.println("Enter total number of player");
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		cricketPlayer[] players = new cricketPlayer[num]; //create array of player of size num
	
		for(int i=0 ; i<num ; i++){
			System.out.println("#####################################");
			System.out.println("Enter name:");
			String name = sc.next();
			System.out.println("Enter innings:");
			 int innings = sc.nextInt();
			System.out.println("Enter notouts:");
			int notouts = sc.nextInt();
			System.out.println("Enter totalruns:");
			int totalruns = sc.nextInt();
			
			players[i] = new cricketPlayer(name,innings,notouts,totalruns);
			
		}
		cricketPlayer.batingAverage(players);
		Arrays.sort(players , (a ,b)-> Double.compare(b.batAvg , a.batAvg));
		
		for(int i=0;i<num;i++)
			System.out.println("Name: "+players[i].name+"\tinnigs: "+players[i].innings+"\tnotouts: "+players[i].notouts+"\ttotalruns: "+players[i].totalruns+"\tBating Average: "+players[i].batAvg);
		
	}
	
}
