import java.util.Scanner;

class Employee {
    int eNo;
    String eName;
    double eSalary;

    // Constructor
    Employee(int no, String name, double salary) {
        eNo = no;
        eName = name;
        eSalary = salary;
    }

    // Method to display employee information
    void displayInfo() {
        System.out.println("Employee Number: " + eNo);
        System.out.println("Employee Name: " + eName);
        System.out.println("Employee Salary: " + eSalary);
    }
}

public class EmployeeMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, choice, searchNo;

        System.out.print("Enter the number of employees: ");
        n = scanner.nextInt();

        // Create an array of Employee objects
        Employee[] employees = new Employee[n];

        // Input employee information
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Employee " + (i + 1) + ":");
            System.out.print("Employee Number: ");
            int empNo = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            System.out.print("Employee Name: ");
            String empName = scanner.nextLine();
            System.out.print("Employee Salary: ");
            double empSalary = scanner.nextDouble();
            employees[i] = new Employee(empNo, empName, empSalary);
        }

        // Menu-driven interface
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Search Employee by Employee Number");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("\nEnter the Employee Number to search: ");
                    searchNo = scanner.nextInt();
                    boolean found = false;
                    for (Employee emp : employees) {
                        if (emp.eNo == searchNo) {
                            System.out.println("\nEmployee found:");
                            emp.displayInfo();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("\nEmployee with Employee Number " + searchNo + " not found.");
                    }
                    break;
                case 2:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 2);

        scanner.close();
    }
}
