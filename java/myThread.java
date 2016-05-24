//学习多线程


class myThread extends Thread{
    private String name;

	public myThread(){

	}
	public myThread(String name){
	this.name = name;
	}
	public void run(){
	for(int i = 0; i<5;i++){
	    System.out.println(name+"运行  "+i);
	}
	}
	public static void main(String[] args){
	myThread h1= new myThread("A");
	myThread h2 = new myThread("B");
	h1.start();
	h2.start();
	}
}