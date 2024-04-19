import java.util.*;

 class StringManipulationDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringManipulator manipulator = new StringManipulator();

        int choice;
        do {
            System.out.println("1. Capitalize first letter");
            System.out.println("2. Check for palindrome");
            System.out.println("3. Count vowels, consonants, digits, and special characters");
            System.out.println("4. Delete all consonants");
            System.out.println("5. Check if a character is present");
            System.out.println("6. Compare strings (case-insensitive)");
            System.out.println("7. Check if string ends with another string");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter a string: ");
                    scanner.nextLine();
                    String capitalizeInput = scanner.nextLine();
                    String capitalized = manipulator.capitalizeFirstLetter(capitalizeInput);
                    System.out.println("Result: " + capitalized);
                    break;
                case 2:
                    System.out.print("Enter a string: ");
                    scanner.nextLine();
                    String palindromeInput = scanner.nextLine();
                    boolean isPalindrome = manipulator.isPalindrome(palindromeInput);
                    if (isPalindrome)
                        System.out.println("The string is a palindrome.");
                    else
                        System.out.println("The string is not a palindrome.");
                    break;
                case 3:
                    System.out.print("Enter a string: ");
                    scanner.nextLine();
                    String countInput = scanner.nextLine();
                    manipulator.countCharacters(countInput);
                    break;
                case 4:
                    System.out.print("Enter a string: ");
                    scanner.nextLine();
                    String deleteConsonantsInput = scanner.nextLine();
                    String withoutConsonants = manipulator.deleteConsonants(deleteConsonantsInput);
                    System.out.println("Result: " + withoutConsonants);
                    break;
                case 5:
                    System.out.print("Enter a string: ");
                    scanner.nextLine();
                    String searchInput = scanner.nextLine();
                    System.out.print("Enter a character to search for: ");
                    char searchChar = scanner.next().charAt(0);
                    boolean isPresent = manipulator.isCharacterPresent(searchInput, searchChar);
                    if (isPresent)
                        System.out.println("The character '" + searchChar + "' is present in the string.");
                    else
                        System.out.println("The character '" + searchChar + "' is not present in the string.");
                    break;
                case 6:
                    System.out.print("Enter the first string: ");
                    scanner.nextLine();
                    String compareInput1 = scanner.nextLine();
                    System.out.print("Enter the second string: ");
                    String compareInput2 = scanner.nextLine();
                    boolean isEqualIgnoreCase = manipulator.compareStringsIgnoreCase(compareInput1, compareInput2);
                    if (isEqualIgnoreCase)
                        System.out.println("The strings are equal (ignoring case).");
                    else
                        System.out.println("The strings are not equal (ignoring case).");
                    break;
                case 7:
                    System.out.print("Enter the main string: ");
                    scanner.nextLine();
                    String endsWithInput = scanner.nextLine();
                    System.out.print("Enter the string to check for ending: ");
                    String endsWithString = scanner.nextLine();
                    boolean endsWith = manipulator.endsWith(endsWithInput, endsWithString);
                    if (endsWith)
                        System.out.println("The main string ends with '" + endsWithString + "'.");
                    else
                        System.out.println("The main string does not end with '" + endsWithString + "'.");
                    break;
                case 8:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 8.");
            }
        } while (choice != 8);

        scanner.close();
    }
}

class StringManipulator {
     String capitalizeFirstLetter(String str) {
        if (str == null || str.isEmpty()) {
            return str;
        }
        return str.substring(0, 1).toUpperCase() + str.substring(1);
    }

     boolean isPalindrome(String str) {
        String reversed = reverseString(str);
        return str.equalsIgnoreCase(reversed);
    }

     void countCharacters(String str) {
        int vowels = 0;
        int consonants = 0;
        int digits = 0;
        int specials = 0;

        str = str.toLowerCase();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    vowels++;
                else
                    consonants++;
            } else if (ch >= '0' && ch <= '9') {
                digits++;
            } else {
                specials++;
            }
        }

        System.out.println("Vowels: " + vowels);
        System.out.println("Consonants: " + consonants);
        System.out.println("Digits: " + digits);
        System.out.println("Special characters: " + specials);
    }

     String deleteConsonants(String str) {
        return str.replaceAll("[^aeiouAEIOU]", "");
    }

     boolean isCharacterPresent(String str, char ch) {
        return str.indexOf(ch) != -1;
    }

     boolean compareStringsIgnoreCase(String str1, String str2) {
        return str1.equalsIgnoreCase(str2);
    }

     boolean endsWith(String str, String suffix) {
        return str.endsWith(suffix);
    }

     String reverseString(String str) {
        return new StringBuilder(str).reverse().toString();
    }
}
