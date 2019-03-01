/**
 * This program reads an integer and prints it 
 * in binary, octal, hexadecimal, and hexadecimal floating-point of the reciprocal
 * @author Cindy
 * @version 2.0 
 * @Date 2018-10-26
 * Purpose : JAC444 Assignment 1
 */
package jac444.wk1;
import java.util.Scanner;

/**
 * Class Name: PrintInt
 */
public class PrintInt{
	/**
	 * Read an integer
	 * @param void
	 * @return Integer
	 */
	public static Integer readInteger() {
		Integer readInt = 0;
    	boolean again = false;
    	do {
    		@SuppressWarnings("resource")
    		Scanner in = new Scanner(System.in);
	    	System.out.print("Please input a integer number: ");
	    	if(in.hasNextInt()) {
	    		readInt = in.nextInt();
	    		again = false;
	    	}
	    	else {
	    		System.out.println("Please try again:");
	    		again = true;
	    	}
    	}while(again);
    	return readInt;
	}
	/**
	 * Print in binary, octal, hexadecimal, and hexadecimal floating-point of the reciprocal 
	 * @param Integer
	 * @return void
	 */
	public static void formatPrint(Integer inInt) {
		System.out.printf("Your Integer in Binary is: %s\n" , Integer.toBinaryString(inInt));
        System.out.printf("Your Integer in Octal is: %s\n" ,Integer.toOctalString(inInt));
        System.out.printf("Your Integer in Hexadecimal is: %s\n" ,Integer.toHexString(inInt));
        System.out.printf("Its Hex-float-point reciprocal is: %a\n", (float)1.0/inInt);
	}
	/**
	 * pause for dramatic appearance 
	 * @param void
	 * @return void
	 */
	public static void pause(String in_read) {
		System.out.println("Your input is : " + in_read + "\n~Press Any Key to Convert...");
		Scanner pause = new Scanner(System.in);
		pause.nextLine();
		pause.close();
	}
	/**
	 * Main will use java.util.Scanner for user input.
	 * @see #readInteger()
	 * @see #pause(String)
	 * @see #formatPrint(Integer)
	 * @param args Not Used.
	 */
    public static void main(String[] args) {
    	// read an integer number
    	Integer readInt = readInteger();
    	// pause
    	pause(Integer.toString(readInt));
    	// Format printing
    	formatPrint(readInt);
    }
}
//Output:
//Please input a integer number: 76
//Your input is : 76
//~Press Any Key to Convert...
//
//Your Integer in Binary is: 1001100
//Your Integer in Octal is: 114
//Your Integer in Hexadecimal is: 4c
//Its Hex-float-point reciprocal is: 0x1.af286cp-7
