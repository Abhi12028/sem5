import java.awt.*;

class Calculator {
	Frame f;
	Button b;
	Label l;
	TextField tf;
	
	Calculator(String name){
		f=new Frame(name);
		
		tf=new TextField();
		tf.setBounds(0,100,400,50);
		f.add(tf);
		
		
		b=new Button("7");
		b.setBounds(0,150,100,50);
		f.add(b);
		b=new Button("4");
		b.setBounds(0,200,100,50);
		f.add(b);
		b=new Button("1");
		b.setBounds(0,250,100,50);
		f.add(b);
		
		
		b=new Button("8");
		b.setBounds(100,150,100,50);
		f.add(b);
		b=new Button("5");
		b.setBounds(100,200,100,50);
		f.add(b);
		b=new Button("2");
		b.setBounds(100,250,100,50);
		f.add(b);
		
		b=new Button("9");
		b.setBounds(200,150,100,50);
		f.add(b);
		b=new Button("6");
		b.setBounds(200,200,100,50);
		f.add(b);
		b=new Button("3");
		b.setBounds(200,250,100,50);
		f.add(b);
		
		b=new Button("0");
		b.setBounds(0,300,300,50);
		f.add(b);
		
		b=new Button("\\");
		b.setBounds(300,150,100,50);
		f.add(b);
		b=new Button("*");
		b.setBounds(300,200,100,50);
		f.add(b);
		b=new Button("-");
		b.setBounds(300,250,100,50);
		f.add(b);
		b=new Button("+");
		b.setBounds(300,300,100,50);
		f.add(b);
		
		
		f.setLayout(null);
		f.setSize(400,400);
		f.setVisible(true);
	}
	public static void main(String[] args){
		 new Calculator("Hello");
	}
}
	

