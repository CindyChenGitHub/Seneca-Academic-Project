/**
 * This program reads an integer and prints it in binary, octal, hexadecimal, and hexadecimal floating-point of the reciprocal
 * @author Cindy
 * @version 2.0 2018-10-26
 */
package jac444.wk1;
import java.util.Scanner;
public class PrintInt{
    public static void main(String[] args) {
    	// read an integer number
    	int num = 0;
    	boolean again = false;
    	do {
    		@SuppressWarnings("resource")
    		Scanner in = new Scanner(System.in);
	    	System.out.print("Please input a integer number: ");
	    	if(in.hasNextInt()) {
	    		num = in.nextInt();
	    		again = false;
	    	}
	    	else {
	    		System.out.println("Please try again:");
	    		again = true;
	    	}
    	}while(again);
    	// print
    	System.out.printf("Banary: %s\n" , Integer.toBinaryString(num)); //show binary
        System.out.printf("Octal: %o\n" ,num); //show octal
        System.out.printf("Hexadecimal: %x\n" ,num); //show hex
        System.out.printf("Reciprocal: %a\n", (float)1.0/num); //show Reciprocal
    }
}
// Output:
// Please input a number: 76
// Banary: 1001100
// Octal: 114
// Hexadecimal: 4c
// Reciprocal: 0x1.af286cp-7
