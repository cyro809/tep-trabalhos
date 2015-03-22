import java.util.Scanner;


public class ananagram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		String[] words = input.split(" ");
		
		for(int i=0;i<words.length;i++) {
			System.out.println(words[i]);
		}
		scan.close();
	}

}
