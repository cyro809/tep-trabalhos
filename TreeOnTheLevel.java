import java.util.Comparator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;



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
		Set<String> keys = nodes.keySet();
		String[] paths = keys.toArray(new String[keys.size()]);
		
		if(!nodes.containsKey("A")) {
			complete = false;
		}
		
		for(int i=paths.length-1;i>paths.length/2;i--) {
			for(int j=paths[i].length();j>0;j--) {
				if(!nodes.containsKey(paths[i].substring(0, j))) {
					complete = false;
					break;
				}
				
				if(!complete) break;
			}
		}
		if(complete) {
			for(int i=0;i<nodes.size();i++) {
				System.out.print(nodes.values().toArray()[i]+" ");
			}
		}
		else {
			System.out.println("not completed");
		}
		
		scan.close();
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

