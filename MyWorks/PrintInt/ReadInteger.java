package Practice.PrintInt;
import java.util.Scanner;
/**
 * This program reads an integer between min and max
 * @author Cindy
 * @version 1.0 2018-10-26
 */

public class ReadInteger {
	private Integer readInt;
	private Integer min;
	private Integer max;
	ReadInteger(){
		this.readInt = null;
		this.min = Integer.MIN_VALUE;
		this.max = Integer.MAX_VALUE;
	}
	ReadInteger(Integer in_min, Integer in_max){
		this.readInt = null;
		this.min = in_min;
		this.max = in_max;
	}
	public void setMin(Integer in_min) {
		this.min = in_min;
	}
	public void setMax(Integer in_max) {
		this.max = in_max;
	}
	public Integer getMin() {
		return this.min;
	}
	public Integer getMax() {
		return this.max;
	}
	private void setInt(Integer in_int) {
		this.readInt = in_int;
	}
	public Integer getInt() {
		return this.readInt;
	}
	/**
	 * pause for dramatic appearance 
	 * @param void
	 * @return void
	 */
	public void pause(String in_read) {
		System.out.println("Your input is : " + in_read + "\n~Press Any Key to Convert...");
		Scanner pause = new Scanner(System.in);
		pause.nextLine();
		pause.close();
	}
	public Integer read() {
		boolean again = false;
		Integer temInt = null;
		Integer min = getMin();
		Integer max = getMax();
		do {
    		@SuppressWarnings("resource")
    		Scanner in = new Scanner(System.in);
    		if(min == Integer.MIN_VALUE)
    			System.out.print("Please input a integer number: ");
    		else
    			System.out.print("Please input a integer number between " + min +" and " + max + ": ");
	    	if(in.hasNextInt()) {
	    		temInt = in.nextInt();
	    		if(temInt<min) {
	    			System.out.println("Your integer needs more then " + getMin() +", try again: ");
	    			again = true;
	    		}
	    		else if(temInt>max) {
	    			System.out.println("Your integer needs less then " + getMax() +", try again: ");
	    			again = true;
	    		}
	    		else {
	    			setInt(temInt);
	    			again = false;
	    		}
	    	}
	    	else {
	    		System.out.println("Your input is not an integer, Please try again:");
	    		again = true;
	    	}
	    	//in.close();
    	}while(again);
		pause(readInt.toString());
		return readInt;
	}
//    public static void read(){
//    	ReadInteger readedInt;
//    	if (args[0] == null)
//    		readedInt = new ReadInteger();
//    	else 
//    		readedInt = new ReadInteger(Integer.valueOf(args[0]), Integer.valueOf(args[1]));
//    	readedInt.read();
//    	readedInt.pause((readedInt.readInt).toString());
//    }
}
