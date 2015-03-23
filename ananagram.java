
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class ananagram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		String[] words = input.split(" ");
		
		HashMap<String, String>word_map = new HashMap<String, String>();
		List<String> result = new ArrayList<String>();
		List<String> alphabetic_words = new ArrayList<String>();
		
		for(int i=0;i<words.length;i++) {
	        char[] chars = words[i].toLowerCase().toCharArray();
	        Arrays.sort(chars);
	        String sorted = new String(chars);
	        
	        alphabetic_words.add(sorted);
			word_map.put(words[i], sorted);
		}
		

		System.out.println(alphabetic_words);
		Collections.sort(alphabetic_words);
		System.out.println(alphabetic_words);
		
		Map<String, Integer> map = new HashMap<String, Integer>();
	    for (String w : alphabetic_words) {
	        Integer n = map.get(w);
	        n = (n == null) ? 1 : ++n;
	        map.put(w, n);
	    }
	    
		for(int i=0;i<map.size();i++) {
			
		}
		
		System.out.println(result);
		scan.close();
	
	}	
	public static Object getKeyFromValue(Map hm, Object value) {
	    for (Object o : hm.keySet()) {
	      if (hm.get(o).equals(value)) {
	        return o;
	      }
	    }
	    return null;
	 }
	
}
