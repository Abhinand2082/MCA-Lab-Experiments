class Account:
        def __init__(self,name,ac_no,type,balance):
                self.name=name
                self.ac_no=ac_no
                self.type=type
                self.balance=balance
        def Deposit(self):
                amount=int(input("Enter the amount: "))
                self.balance=self.balance+amount
        def Withdraw(self):
                amount=int(input("Enter the amount: "))
                if(self.balance>=amount):
                        self.balance=self.balance-amount
                """else:
			print("Not enough balance:")"""
        def display(self):
                print("Name of account holder: ",self.name)
                print("Account number: ",self.ac_no)
                print("Type of account: ",self.type)
                print("Balance is :",self.balance)
p1=Account("Abhinand",3434310,"Savings",0)
choice=0
while(choice!=-1):
        choice=int(input("\n1.Deposit\n2.Withdraw\n3.Display\n-1.Exit\nEnter the choice: "))
        if(choice==1):
                p1.Deposit()
        elif(choice==2):
                p1.Withdraw()
        elif(choice==3):
                p1.display()
        else:
                print("Exiting")
