/**
 * This program reads an integer and prints it 
 * in binary, octal, hexadecimal, and hexadecimal floating-point of the reciprocal
 * @author Cindy
 * @version 2.0 
 * @Date 2018-10-26
 * Purpose : JAC444 Assignment 1
 */
package Practice.PrintInt;
//import java.util.Scanner;
import Practice.PrintInt.ReadInteger;
/**
 * Class Name: PrintInt
 */
public class PrintInt{
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
	 * Main will use java.util.Scanner for user input.
	 * @see #readInteger()
	 * @see #pause(String)
	 * @see #formatPrint(Integer)
	 * @param args Not Used.
	 */
    public static void main(String[] args) {
    	// read an integer number
    	ReadInteger readInt = new ReadInteger();
    	//ReadInteger readInt = new ReadInteger(35,79);
    	// Format printing
    	formatPrint(readInt.read());
    }
}
//	Output:
//	Please input a integer number: 76
//	Your input is : 76
//	~Press Any Key to Continue...
//	
//	Your Integer in Binary is: 1001100
//	Your Integer in Octal is: 114
//	Your Integer in Hexadecimal is: 4c
//	Its Hex-float-point reciprocal is: 0x1.af286cp-7
