/*
 * Getting Chorded
 * http://acm.uva.es/p/v3/346.html
 * 
 * Victoria Wu, Fall 2012
 * Status: Complete
 * Determine if the following sets of three notes form a major, minor, or unrecognized chord.
 *
 * Sample Input:
 * C E G
 * C E F#
 * G C E
 * C Eb G
 * c# a f#
 * f g# C
 *
 */
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string> 


using namespace std;

int main()	{
	
	//Create our map. 

	map<string, int> notes;

	notes["C"] = 1;
	notes["C#"] = 2;
	notes["DB"] = 3;
	notes["D"] = 3;
	notes["D#"] = 4;
	notes["EB"] = 4;
	notes["E"] = 5;
	notes["F"] = 6;
	notes["F#"]= 7;
	notes["GB"] = 7;
	notes["G"] = 8;
	notes["G#"] = 9;
	notes["AB"] = 9;
	notes["A"] = 10;
	notes ["A#"] = 11;
	notes["BB" ] = 11;
	notes["B"] = 12;

	string firstNote = "";
	string secondNote = "";
	string thirdNote = "";
	while(cin >> firstNote)	{
		cin >> secondNote >> thirdNote;

		firstNote = toupper(firstNote);

		//Convert strings to capital case except the second b

		//Sort the notes.
		vector<string> chord;
		vector<string> ::iterator it; 
		chord.push_back(firstNote);
		chord.push_back(secondNote);
		chord.push_back(thirdNote);

		sort(chord.begin(), chord.end());

		//cout << "Printing out sorted chord" <<endl;
		for(it = chord.begin(); it != chord.end(); it++)	{
			cout << " " << *it;
		}


		bool found = false;
		int permutation = 0;
		while(permutation <3 && !found)	{
			int firstGap = notes[chord[1]] - notes[chord[0]];
			int secondGap = notes[chord[2]] - notes[chord[1]];

			if(secondGap <0)
				secondGap += 12;
			if(firstGap <0)
				firstGap +=12;

			//cout << "First gap " << firstGap << endl;
			//cout << "Second gap" << secondGap <<endl; 

			if(firstGap == 4 && secondGap == 3)	{
				//Major chord!!
				cout <<  firstNote << " " << secondNote << " " << thirdNote  <<" is a " 
				<< chord[0] << " Major chord." <<endl;
				found = true;	
			}
			else if(firstGap == 3 && secondGap == 4)	{
			cout <<  firstNote << " " << secondNote << " " << thirdNote  << " is a " 
				<< chord[0] << " Minor chord." <<endl;
				found = true;
			}

			//Take out last note, put in the first.
			string last = chord.back();
			chord.pop_back();
			it = chord.begin();
			chord.insert(it, last);

			permutation++;
		}


		if(!found)	{
			cout << firstNote << " " << secondNote << " " << thirdNote << " is unrecognized." <<endl;
		}

	}

}
