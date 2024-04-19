import java.util.*;
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

class VoteElig {
    public static void main(String[] args) {
	Scanner s=new Scanner(System.in);
	System.out.println("Enetr your age:");
	 int age = s.nextInt(); 
        try {
            checkVotingEligibility(age);
            System.out.println("You are eligible to vote.");
        } catch (InvalidAgeException e) {
            System.out.println(e.getMessage());
        }
	s.close();
    }

    public static void checkVotingEligibility(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Sorry, you are not eligible to vote.");
        }
    }
}
