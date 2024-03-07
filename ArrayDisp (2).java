/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.Scanner;
public class ArrayDisp
{
	public static void main(String[] args) {
	    int[]array = new int[5];
	    Scanner sc = new Scanner(System.in);
	  
		System.out.println("Original Array:");
		for(int i=0;i<array.length;i++){
		    System.out.println("Enter Integer");
		    array[i]=sc.nextInt();
		}
		for(int i=0;i<array.length;i++){
		    System.out.println(array[i]);
		}
	}
}
