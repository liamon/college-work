package lab1;

import java.util.Scanner;

public class Fibonacci {
	public static void main(String[] args) {
		int t1 = 0, t2 = 1, nextTerm = 0, n;
		
		System.out.print("Enter a positive integer: ");
		Scanner scanInt = new Scanner(System.in);
		n = scanInt.nextInt();
		
		System.out.printf("Fibonacci Series: %d, %d, ", t1, t2);
		
		nextTerm = t1 + t2;
		
		while (nextTerm < n) {
			System.out.printf("%d, ", nextTerm);
			t1 = t2;
			t2 = nextTerm;
			nextTerm = t1 + t2;
		}
	}
}
