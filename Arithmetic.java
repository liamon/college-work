package lab1;

public class Arithmetic {
	public static void main(String[] args) {
		int a = 9, b = 4, c;
		
		c = a + b;
		System.out.printf("a+b = %d \n", c);

		c = a - b;
		System.out.printf("a-b = %d \n", c);

		c = a * b;
		System.out.printf("a*b = %d \n", c);

		c = a / b;
		System.out.printf("a/b = %d \n", c);

		c = a % b;
		System.out.printf("Remainder when a divided by b = %d \n", c);
	}
}
