/*
 * Automatic Editing
 * Perceptive Software Code Rush 2012 Problem 9
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1056
 *
 * Status: COMPLETE 
 * Victoria Wu, Marvin Bellamy
 * 2/6/13
 */

import java.io.*;
import java.util.*;	//scanner, hashmap

//pair class modified from
//http://stackoverflow.com/questions/156275/what-is-the-equivalent-of-the-c-pairl-r-in-java

class Pair<A, B>	{
	public A first; public B second;
	public Pair(A one, B two)	{first = one; second =two;}
}

public class automaticEditing	{
	public static void main(String args[]) throws IOException	{
		
		Scanner in = new Scanner(new FileReader("autoedit.in"));
		
		//Be careful when intermixing next and nextline. Next will only take up to \n	
		int rules = Integer.parseInt(in.nextLine());
		String key, value;
		String meat;
		ArrayList<Pair<String, String> > m = new ArrayList<Pair<String, String>>();
		while(rules != 0)	{

			//Getting the rules
			while(rules != 0)	{
				key = in.nextLine();
				value = in.nextLine();
				rules--;
				m.add(new Pair<String, String>(key, value));
				//System.out.println("READ IN: " + key + " = " + value);
			}	

			//Chopping up the sentence
			meat = in.nextLine();	
			//System.out.println("MEAT: " + meat);
			for(Pair<String, String> entry : m)	{	
				//System.out.println("Applying rule: " + entry.first + " = " + entry.second);
				while(meat.indexOf(entry.first) != -1)	{
					meat = meat.replaceFirst(entry.first, entry.second);
				}		
			}
			System.out.println(meat);

			//clearing array list
			m.clear();
			rules = Integer.parseInt(in.nextLine());

		}
		in.close();
	}
}
