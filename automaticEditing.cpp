
/*
 * automatic editing
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1056
 *
 * Perceptive Software Code Rush 2012 C++
 * 2/7/13 status: complete
 */
#include <iostream>
#include <fstream>
#include <utility>	//pair
#include <vector>	
#include <string>	//string replace and find
using namespace std;

int main()	{
	
	fstream fin;
	fin.open("autoedit.in", fstream::in);
	
	int rules;
	string buffer, key, value, meat;
	vector<pair <string, string> > m;	
	vector<pair <string, string> >::iterator it;
	getline(fin, buffer);
	rules = atoi(buffer.c_str());
	
	while(rules != 0)	{

		//Grabbing rules
		while(rules != 0)	{
			getline(fin, key);
			getline(fin, value);
			m.push_back(pair<string, string>(key, value));
			rules--;	
		}
		//Chopping up the sentence
		getline(fin, meat);
		
		for(it = m.begin(); it != m.end(); it++)	{
			while( meat.find(it->first) != string::npos)	{
				meat = meat.replace(meat.find(it->first), it->first.length(), it->second);		
			}
		}
		cout << meat << endl;

		//clearing vector
		m.clear();
		getline(fin, buffer);
		rules = atoi(buffer.c_str());
	}	
	fin.close();

}
