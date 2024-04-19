class accountDemo{
 String name,acc_type;
 int acc_no;
 float balance,amount;
 accountDemo(String name,int acc_no,String acc_type, float balance){
 this.name=name;
 this.acc_no=acc_no;
 this.acc_type=acc_type;
 this.balance=balance;
 }
 void deposit(float amount){
 balance=balance+amount;
 System.out.println("Deposited Success");
}
void withdraw(float amount){
 if(amount>balance){
 System.out.println("Insufficient Balance");
 }else{
balance=amount;
}
}
void display(){
 System.out.println("Name:"+name);
 System.out.println("Account Number:"+acc_no);
 System.out.println("Account Type:"+acc_type);
 System.out.println("Balance:"+balance);

}
}
class Bank{
	public static void main(String args[]){
	accountDemo a1=new accountDemo("Manoj",10003,"Savings",20000f);
	a1.display();
	System.out.println("Depositing 3000f");
	a1.deposit(3000f);
	a1.display();
	System.out.println("Widthrwaing 15000f");
	a1.withdraw(3000f);
	a1.display();
	}
}
