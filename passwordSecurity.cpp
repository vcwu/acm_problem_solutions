/*
 * Password Security
 * Perceptive Software 2012 Contest Problem 2
 * http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1698
 *
 * Status: Complete
 * Victoria Wu
 * 2/6/13
 */

#include <iostream>
#include <fstream>
#include <string>	//for str compare
#include <stdio.h> 	//printf
using namespace std;

bool passwordOK(string pw);

int main()	{
	
	//Get each password.
	fstream fin;
	fin.open("password.txt", fstream::in);
	string pw = "";
	fin >> pw;
	
	while(pw.compare("end") != 0)	{
		if(passwordOK(pw))
			printf("<%s> is acceptable.", pw.c_str());
		else
			printf("<%s> is not acceptable.", pw.c_str());	
		cout <<endl;
		fin >>pw;
	}
	fin.close();
}

bool passwordOK(string pw)	{

	bool hasVowel = false;		
	string vowels = "aeiou";
	char prevChar = ' ';		//keeps track of prev char
	int vowelCount = 0;		//count vowels in a row
	int consCount = 0;		//count consanants in a row
	string::iterator it, end;	//used for stepping through string


	//Step through char by char.
	for(it = pw.begin(), end = pw.end(); it!= end; it++)	{
			
		//Vowel?
		//---------------------------------
		if(vowels.find(*it) != string::npos)	{
			hasVowel = true;
			vowelCount++;
			consCount = 0;
		}
		//Consonant.
		//--------------------------------
		else	{
			vowelCount = 0;
			consCount++;
		}
		
		//Check for three in a row.
		if(vowelCount == 3 || consCount ==3)	{
			return false;
		}

		//Check for double char.
		if( ((*it) == prevChar) && (*it != 'e' && *it != 'o'))	{
			return false;
		}

		//remember char for next step
		prevChar = *it;		
	}
	
	return hasVowel;
}
