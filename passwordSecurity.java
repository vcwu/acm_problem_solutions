/*
 * password security
 * Perceptive Software Code Rush 2012 Problem 2
 * http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1698
 * status: complete 
 * Victoria Wu
 * 2/6/13
 */

import java.util.*;	//Scanner
import java.io.*;

public class passwordSecurity	{
	public static void main(String args[]) throws IOException	{
		
		Scanner in = new Scanner(new FileReader("password.txt"));
		String pw  = "";
		while(in.hasNext())	{
			pw = in.next();
			if(passwordOK(pw))
				System.out.println("<" + pw + "> is acceptable.");
			else
				System.out.println("<" + pw + "> is not acceptable.");
			
		}
		in.close();
	}

	public static boolean passwordOK(String str)	{
		String vowels = "aeiou";
		boolean vowelOK = false;
		char prevLetter = ' ';
		int vowelCount = 0;
		int consCount = 0;

		for(int i =0; i< str.length(); i++)	{
			char c = str.charAt(i);
			//there's a vowel!
			if(vowels.indexOf(c) != -1)	{
				vowelOK = true;
				vowelCount++;
				consCount = 0;
			}
			else	{
				vowelCount = 0;
				consCount++;
			}

			if(vowelCount ==3 || consCount == 3)
				return false;

			if(prevLetter ==c && prevLetter != 'e' && prevLetter != 'o')
				return false;
				
		       	prevLetter = c;
		}
		return vowelOK;
	}
}
