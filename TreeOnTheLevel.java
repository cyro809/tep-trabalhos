import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



public class TreeOnTheLevel implements Comparator<String>{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String input = "";
		Boolean complete = true;
		
		while(true) {
			input += scan.nextLine()+" ";
			if(input.contains("()")) {
				break;
			}
		}
		input = input.replace("(", "");
		input = input.replace(")", "");
		String[] result= input.split(" ");
		
		TreeOnTheLevel comp = new TreeOnTheLevel();
		Map<String, Integer> nodes = new TreeMap<String, Integer>(comp);
		
		for(String s: result) {
			if(s.split(",").length > 1) {
				//TODO Criar try catch para pegar o caso de um nó sem valor (ex: (,LR))
				try {
					nodes.put(s.split(",")[1], Integer.parseInt(s.split(",")[0]));
				} 
				catch (NumberFormatException e) {
					complete = false;
				}
				
			}
			else {
				nodes.put("A", Integer.parseInt(s.split(",")[0]));
			}
			
		}
		
		if(complete) {
			System.out.println(nodes.values());
		}
		else {
			System.out.println("not completed");
		}
		
		
	}
	
	public int compare(String s1, String s2) {
    	if(s1.length() < s2.length()) {
            return -1;
        }
        if(s1.length() > s2.length()) {
            return 1;
        }   
        if(s1.compareTo(s2) < 0){
            return -1;
        }
        if(s1.compareTo(s2) > 0){
            return 1;
        }
        else
            return 0;
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

