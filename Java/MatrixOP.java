import java.util.Scanner;

public class MatrixOP {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows for matrices: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns for matrices: ");
        int columns = scanner.nextInt();

        int[][] matrixA = new int[rows][columns];
        int[][] matrixB = new int[rows][columns];

        System.out.println("Enter elements for Matrix A:");
        fillMatrix(matrixA, scanner);

        System.out.println("Enter elements for Matrix B:");
        fillMatrix(matrixB, scanner);

        while (true) {
            System.out.println("\nMatrix Operations Menu:");
            System.out.println("1. Matrix Addition");
            System.out.println("2. Matrix Subtraction");
            System.out.println("3. Matrix Multiplication");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1-4): ");
            
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    displayMatrix(addMatrices(matrixA, matrixB));
                    break;
                case 2:
                    displayMatrix(subtractMatrices(matrixA, matrixB));
                    break;
                case 3:
                    displayMatrix(multiplyMatrices(matrixA, matrixB));
                    break;
                case 4:
                    System.out.println("Exiting the program. Goodbye!");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 4.");
            }
        }
    }

    private static void fillMatrix(int[][] matrix, Scanner scanner) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print("Enter element at position (" + (i + 1) + "," + (j + 1) + "): ");
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    private static int[][] addMatrices(int[][] matrixA, int[][] matrixB) {
        int rows = matrixA.length;
        int columns = matrixA[0].length;
        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        return result;
    }

    private static int[][] subtractMatrices(int[][] matrixA, int[][] matrixB) {
        int rows = matrixA.length;
        int columns = matrixA[0].length;
        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        return result;
    }

    private static int[][] multiplyMatrices(int[][] matrixA, int[][] matrixB) {
        int rowsA = matrixA.length;
        int columnsA = matrixA[0].length;
        int columnsB = matrixB[0].length;
        int[][] result = new int[rowsA][columnsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsB; j++) {
                for (int k = 0; k < columnsA; k++) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return result;
    }

    private static void displayMatrix(int[][] matrix) {
        System.out.println("Resultant Matrix:");
        for (int[] row : matrix) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}
