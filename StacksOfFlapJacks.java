import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class StacksOfFlapJacks {

	/**
	 * @param args
	 */
	public static int flips = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		List<Integer> list = new ArrayList<Integer>();
		int maxIndex;
		String[] num_string = scanner.nextLine().split(" ");
		
		Integer[] arr = new Integer[num_string.length];
		for(int i=0;i<arr.length;i++) {
			arr[i] = Integer.parseInt(num_string[i]);
		}
		for(int n: arr) {
			System.out.print(n+" ");
		}
		System.out.println();
		for(int i= arr.length;i>1;i--) {
			maxIndex = maxIndexNumber(arr, i);
			if(maxIndex != i-1) {
				flip(arr, maxIndex);
				
				flip(arr, i-1);
				StacksOfFlapJacks.flips++;
				System.out.print(StacksOfFlapJacks.flips+" ");
			}
		}
		System.out.print("0");
		
		scanner.close();
	}
	
	public static void flip(Integer arr[], int n) {
		Integer temp;
		Integer start = 0;
		while (start < n) {
			temp = arr[start];
			arr[start] = arr[n];
			arr[n] = temp;
			start++;
			n--;
		}
		
		
	}
	
	public static int maxIndexNumber(Integer arr[], int n) {
		int maxIndex = 0;
		for (int i = 1; i < n; i++){
		   int newnumber = arr[i];
		   if ((newnumber > arr[maxIndex])){
		   maxIndex = i;
		  }
		}
		return maxIndex;
	}

}
