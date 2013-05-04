#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
int currentArrayPosition;
int findLengthOfQuestion(int questionNumber);
string entireFile;
string* storyArray;
string* buffer;
int gameOver = 0;
int answer[4];
int answerstaken = 0;
int startingpos = 0;

/* 
readIn() function reads the story's text into
a string that will be parsed and evaluated.
*/

void readIn()
{
	buffer = new string[4000];
	ifstream myfile ("story.txt");

	if (myfile.is_open()) 
	{
		int i=0;
		while (myfile.good()) 
		{
			myfile >> buffer[i];   
			entireFile += buffer[i];  
			i++; 
		}
		myfile.close();
	}
}

/*
displayLine(int pos) function takes one parameter which
is the index for starting position for the string
containing the story. From this starting position,
the questions and answers associated with it
will be displayed to the terminal.
*/

void displayLine(int pos)
{
	int printStuff = 0;
	answerstaken =0;

	for (int i=pos; i < entireFile.length(); i++) 
	{

		if (entireFile[i] != '@')
		{
			if(entireFile[i] == ':')
			{
				printStuff = 1;
				i+= 2;
			}

			if(entireFile[i] == '_' && printStuff ==1)
				cout << ' ';
			else if(entireFile[i] == '+'&& printStuff ==1)
				cout << endl << endl;
			else if(entireFile[i] == '>'&& printStuff ==1)
			{
				i++;
				answer[answerstaken] = atoi(entireFile.substr(i,4).c_str());
				i+=3;
				answerstaken++;
			}
			else if (printStuff == 1)
				cout << entireFile[i];
		}
		else
			break;
	}
}

/*
inputChoice() function waits for the user to
input a letter choice to continue the story.
Based on the response the function returns a 
value which is later decoded.
*/

int inputChoice()
{
	string x;
	cin >> x;

	string a = "a";
	string b = "b";
	string c = "c";
	string d = "d";
	string A = "A";
	string B = "B";
	string C = "C";
	string D = "D";

	if(x == a || x == A)
		return 0;
	if(x == b || x == B)
		return 1;
	if(x == c || x == C)
		return 2;
	if(x == d || x == D)
		return 3;
}

/*
errorMessage() function displays an 
error message if an input selected
by the user isn't avliable.
*/
void errorMessage()
{
	cout << "Not a valid option pick again? \n" ;
}

/*
main() function
*/

int main()
{	

	for(int i = 0; i < 4; i++)
		answer[i] = -1;

	readIn();


	while(!gameOver)
	{
		system("clear");
		displayLine(startingpos);
		stringstream ss;
		int choice = inputChoice();
		while(choice > answerstaken - 1)
		{
			errorMessage();
			choice = inputChoice();
		}

		if(answer[choice] == 9999)
		{
			system("clear");
			cout << "Thanks For Playing! \n";
			exit(0);
		}

		ss << answer[choice];
		string jump = ss.str() + ":";
		startingpos = entireFile.find(jump);
	}
	return 0;
}
