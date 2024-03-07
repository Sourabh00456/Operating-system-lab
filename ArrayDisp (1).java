/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class ArrayDisp
{
	public static void main(String[] args) {
	    int[]array = new int[5];
	    
	    array[0]=10;
	   array[1]=20;
	    array[2]=30;
	     array[3]=40;
	     array[4]=50;
		System.out.println("Original Array:");
		for(int i=0;i<array.length;i++){
		    System.out.println("Element at index"+i+":"+array[i]);
		}
	}
}
