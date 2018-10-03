package jac444.wk1;

import java.util.Scanner;

public class PrintInt {

	public static void main(String[] args) {
		System.out.printf("Input a number: ");
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		System.out.println("Banary: " + Integer.toBinaryString(number)); //show binary
        System.out.println("Octal: " + Integer.toOctalString(number)); //show octal
        System.out.println("Hexadecimal: " + Integer.toHexString(number)); //show hex
        float reciprocal = (float)1.0/number;
        System.out.printf("Reciprocal: %a", reciprocal); 
        in.close();
	}
}
