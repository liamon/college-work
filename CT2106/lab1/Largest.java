package lab1;

import java.util.Scanner;

public class Largest {
	public static void main(String[] args) {
		double n1, n2, n3;
		
		System.out.print("Enter 3 numbers: ");
		Scanner scanNums = new Scanner(System.in);
		n1 = scanNums.nextDouble();
		n2 = scanNums.nextDouble();
		n3 = scanNums.nextDouble();
		
		if (n1 >= n2) {
			if (n1 >= n3) {
				System.out.printf("%.2f is the largest number.", n1);
			} else {
				System.out.printf("%.2f is the largest number.", n3);
			}
		} else {
			if (n2 >= n3) {
				System.out.printf("%.2f is the largest number.", n2);
			} else {
				System.out.printf("%.2f is the largest number.", n3);
			}
		}
	}
}
