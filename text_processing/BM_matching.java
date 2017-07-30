package practice;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
/*
 * O(mn)
 * 
 */

public class Demo10_1_BM_matching {

	public static int findBoyerMoore(char[] text, char[] pattern){
		int n = text.length;
		int m = pattern.length;
			
		if(m == 0) return 0;
		Map<Character, Integer> last = new HashMap<>();
		
		for(int i = 0; i < n; i++)
			last.put(text[i], -1);  //set -1 as default for all text characters
		for(int k = 0; k < m; k++)
			last.put(pattern[k], k);  //rightmost occurrence in pattern is last
		
		//start with the end of the pattern aligned at index m-1 of the text
		int i = m - 1;					// an index into the text
		int k = m - 1;					// an index into the pattern
		while(i < n){
			if(text[i] == pattern[k]){	// a matching character
				if(k == 0) return i;	// entire pattern has been found
				i--;					// otherwise, examine previous
				k--;					// character of text/pattern
			}else{
				i += m - Math.min(k, 1 + last.get(text[i])); // case analysis for jump step
				k = m - 1;				// restart at end of pattern
			}
		}
		
		return -1;						// pattern was never found 
	}
	
	public static int BM(char[] text, char[] pattern)
	{	
		int n = text.length;
		int m = pattern.length;
				
		if(m == 0) return 0;
		
		Map<Character, Integer> last = new HashMap<>();
		for(int i = 0; i < n; i++){
			last.put(text[i], -1);
		}
		for(int i = 0; i < m; i++){
			last.put(pattern[i], i);
		}
		
		int i = m - 1;
		int k = m - 1;
			
		while(i < n){	
			if(text[i] == pattern[k]){
				if(k == 0) return i;
				i--;
				k--;
			}else{
				i += m - Math.min(k, 1 + last.get(text[i]));
				k = m - 1;
			}
		}
	
		return -1;
	}
	
	
	
	
	
	
	public static void main(String[] args) {
		
		String str1 = "hellochinadaca";
		String str2 = "china";
		char[] text = str1.toCharArray();
		char[] pattern = str2.toCharArray();
		
		int index = BM(text, pattern);
		
		System.out.println("index: " + index);
	}
	
	
}
