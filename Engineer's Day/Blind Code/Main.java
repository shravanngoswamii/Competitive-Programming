import java.util.Scanner;
import java.io.*;


public class Main {
    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (Exception e) {
            System.err.println(e);
        }

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(n + n);
    }
}
