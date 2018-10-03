package jac444.wk1;

import java.util.Scanner;

public class IsSquare {

	public static void main(String[] args) {
		System.out.print("Give an odd number (ex.3): ");
		Scanner in = new Scanner(System.in);
		int size = in.nextInt();
		int totalSize = size * size;
		int[][] arr = new int[size][size];
		System.out.printf("Give %d. numbers, sparate with blackspace, end with enter (ex.4 9 2 3 5 7 8 1 6): ", totalSize);
		for (int row=0; row<size; row++) {
			for (int col = 0; col<size; col++) {		
				arr[row][col] = in.nextInt();
			}			
		}
		
		boolean isMagic = true;
	    final int magicNumber = (size * size * (size * size + 1) / 2) / size;
	    int sumOfRow = 0, sumOfColoumns = 0, sumOfPrimaryDiagonal = 0, sumOfSecondaryDiagonal = 0;
	    boolean[] flag= new boolean[size * size];

	    for (int row = 0; row < size; row++) {
	        sumOfRow = 0;
	        sumOfColoumns = 0;
	        for (int col = 0; col < size; col++) {
	            if (arr[row][col] < 1 || arr[row][col] > totalSize) {
	                isMagic = false;
	            }
	            if (flag[arr[row][col] - 1] == true) {
	                isMagic =  false;
	            }
	            flag[arr[row][col] - 1] = true;
	            sumOfRow += arr[row][col];
	            sumOfColoumns += arr[col][row];
	        }
	        sumOfPrimaryDiagonal += arr[row][row];
	        sumOfSecondaryDiagonal += arr[row][size-row-1];
	    }
        if (sumOfRow != magicNumber || sumOfColoumns != magicNumber) {
        	isMagic = false;
        }
        if (sumOfPrimaryDiagonal != magicNumber || sumOfSecondaryDiagonal != magicNumber) {
        	isMagic = false;
        }
	    
	    System.out.println("isMagicSquare: " + isMagic);
		in.close();
	}
}
