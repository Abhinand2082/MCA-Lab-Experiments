import java.util.*

class StringArr {
     String[] arrayOfStrings;
     int numOfStrings;

     StringArr() {
        arrayOfStrings = new String[0];
        numOfStrings = 0;
    }

     void addString(String newString) {
        arrayOfStrings = Arrays.copyOf(arrayOfStrings, numOfStrings + 1);
        arrayOfStrings[numOfStrings] = newString;
        numOfStrings++;
    }

     boolean searchString(String target) {
        for (String str : arrayOfStrings) {
            if (str.equals(target)) {
                return true;
            }
        }
        return false;
    }

     void sortStrings() {
        Arrays.sort(arrayOfStrings);
    }

     String[] getArray() {
        return arrayOfStrings;
    }
}





 class StringArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringArr str = new StringArr();

        int choice;
        do {
            System.out.println("Menu:");
            System.out.println("1. Add string to the array");
            System.out.println("2. Search for a string");
            System.out.println("3. Sort the strings");
            System.out.println("4. Display the array");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the string to add: ");
                    String newString = scanner.next();
                    str.addString(newString);
                    System.out.println("String added successfully.");
                    break;

                case 2:
                    System.out.print("Enter the string to search: ");
                    String searchString = scanner.next();
                    boolean searchResult = str.searchString(searchString);
                    System.out.println("String found: " + searchResult);
                    break;

                case 3:
                    str.sortStrings();
                    System.out.println("Strings sorted successfully.");
                    break;

                case 4:
                    System.out.println("Current array of strings: " + Arrays.toString(str.getArray()));
                    break;

                case 0:
                    System.out.println("Exiting the program");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 0);

        scanner.close();
    }
}
