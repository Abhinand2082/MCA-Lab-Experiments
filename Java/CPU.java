import java.util.*;

public class CPU {
    private double price;
    private Processor processor;
    private RAM ram;

    public CPU(double price) {
        this.price = price;
    }

    // Inner class Processor
    class Processor {
        private int numOfCores;
        private String manufacturer;

        public Processor(int numOfCores, String manufacturer) {
            this.numOfCores = numOfCores;
            this.manufacturer = manufacturer;
        }

        public void getProcessorInfo() {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter Number Of Cores:");
            numOfCores = scanner.nextInt();
            scanner.nextLine(); 
            System.out.println("Enter Manufacturer:");
            manufacturer = scanner.nextLine();
        }

        public void printProcessorInfo() {
            System.out.println("Processor Information:");
            System.out.println("Number of Cores: " + numOfCores);
            System.out.println("Manufacturer: " + manufacturer);
        }
    }

    // Static nested class RAM
    static class RAM {
        private int memory;
        private String manufacturer;

        public RAM(int memory, String manufacturer) {
            this.memory = memory;
            this.manufacturer = manufacturer;
        }

        public void getRAMInfo() {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter RAM Capacity:");
            memory = scanner.nextInt();
            scanner.nextLine(); 
            System.out.println("Enter RAM Manufacturer:");
            manufacturer = scanner.nextLine();
        }

        public void printRAMInfo() {
            System.out.println("RAM Information:");
            System.out.println("Memory: " + memory + "GB");
            System.out.println("Manufacturer: " + manufacturer);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double price;
        System.out.print("Enter CPU Price: $");
        price = scanner.nextDouble();
        CPU cpu = new CPU(price);

        int choice;
        do {
            System.out.println("\n1. Enter Processor Information");
            System.out.println("2. Enter RAM Information");
            System.out.println("3. View Processor Information");
            System.out.println("4. View RAM Information");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    cpu.processor = cpu.new Processor(0, "");
                    cpu.processor.getProcessorInfo();
                    break;
                case 2:
                    cpu.ram = new RAM(0, ""); //instantiate
                    cpu.ram.getRAMInfo();
                    break;
                case 3:
                    if (cpu.processor == null) {
                        System.out.println("Processor information is not available.");
                    } else {
                        cpu.processor.printProcessorInfo();
                    }
                    break;
                case 4:
                    if (cpu.ram == null) {
                        System.out.println("RAM information is not available.");
                    } else {
                        cpu.ram.printRAMInfo();
                    }
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        } while (choice != 5);
        scanner.close();
    }
}
