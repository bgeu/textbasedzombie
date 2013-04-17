#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int currentArrayPosition;
int findLengthOfQuestion(int questionNumber);
string entireFile;
string* storyArray;

int main()
{
	string line;
	storyArray = new string[1000];
	ifstream myfile ("story.txt");

	if (myfile.is_open())
	{
		int i=0;
		while (myfile.good())
		{

			//getline(myfile, line);
			myfile >> storyArray[i]; //= line;	
			entireFile += storyArray[i];	
			i++;
		}
		myfile.close();
	}

	string temp;
	for (int i=0; i < entireFile.length(); i++)
	{
		if (entireFile[i] != '\n')
		{
			temp[i] = entireFile[i];
		}
		else
			break;
	}
	
	temp.replace(0,3, "");
	cout << temp << endl;
	
	char x;
	findLengthOfQuestion(1);
	cin >> x;
	
	for (int i = currentArrayPosition+1; i < storyArray->size(); i++)
	{
		if (storyArray[i][0] == x)
		{
			int tempPosition = storyArray[i].find("->");
			int jump  = tempPosition+3;
			//convert string to int
			//now we have the jump and repeat
			

		}
			
	}
	
	
	return 0;
}

int findLengthOfQuestion(int questionNumber)
{
	string questionString;
	ostringstream oss;
	oss << questionNumber;
	questionString = oss.str();
	
	entireFile.find(questionString);

	int arrayNumber;
	int count=0;
	char questionChar = questionString[0];
	for (int i=0; i < storyArray->size(); i ++)
	{
		if (storyArray[i].at(0) == questionChar)
		{
			arrayNumber = i;
			currentArrayPosition = i;
			break;
		}
		 
	}	

	for (int i=arrayNumber;  i < storyArray->size(); i ++)
	{
		if (!storyArray[i].empty())
		{	
			count++;
			
			string temp = storyArray[i];
			int pos = temp.find("->");
			temp.replace(pos, pos+4, "");
			//temp.erase(pos, pos+4);
			cout << temp << endl;	
			
		}
	}
	return count;
}
