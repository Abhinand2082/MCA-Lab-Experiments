import java.util.ArrayList;
import java.util.Scanner;

class BankAccount {
    private int accountNumber;
    private double balance;

    public BankAccount(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }
}

class Bank {
    private String bankName;
    private ArrayList<BankAccount> accounts;

    public Bank(String bankName) {
        this.bankName = bankName;
        this.accounts = new ArrayList<>();
    }

    public void addBankAccount(BankAccount account) {
        accounts.add(account);
    }

    public void removeBankAccount(int accountNumber) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts.get(i).getAccountNumber() == accountNumber) {
                accounts.remove(i);
                return;
            }
        }
        System.out.println("Account with account number " + accountNumber + " not found.");
    }

    public void displayBankAccounts() {
        System.out.println("Bank Accounts in " + bankName + ":");
        for (BankAccount account : accounts) {
            System.out.println("Account Number: " + account.getAccountNumber() + ", Balance: " + account.getBalance());
        }
    }
}

public class BankMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bank bank = new Bank("MyBank");

        int choice;
        do {
            System.out.println("\n1. Add Bank Account");
            System.out.println("2. Remove Bank Account");
            System.out.println("3. Display Bank Accounts");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter account number: ");
                    int accountNumber = scanner.nextInt();
                    System.out.print("Enter initial balance: ");
                    double balance = scanner.nextDouble();
                    bank.addBankAccount(new BankAccount(accountNumber, balance));
                    break;
                case 2:
                    System.out.print("Enter account number to remove: ");
                    int accNumberToRemove = scanner.nextInt();
                    bank.removeBankAccount(accNumberToRemove);
                    break;
                case 3:
                    bank.displayBankAccounts();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 4);
        scanner.close();
    }
}
