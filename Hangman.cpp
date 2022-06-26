#include<bits/stdc++.h>
using namespace std;
string toLowerCase(const string& s)
{
	string res=s;
	int sz=s.size();
	for(int i=0;i < sz; i++)
	{
		res[i] = tolower(s[i]);
	}
	return res;
}
void display_misses(int misses)
{
  if(misses==0)
  {
    cout<<"  +---+ \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==1)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==2)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==3)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==4)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==5)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==6)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==7)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }

}
string chooseWord(string fileName)
{
	vector<string> wordList;
	ifstream file(fileName);
	if(file.is_open())
	{
		string word;
		while(file >> word)
		{
			wordList.push_back(word);
		}
		file.close();
	}
	if(wordList.size()>0)
	{
		int randomIndex = rand() % 	wordList.size();
		return toLowerCase(wordList[randomIndex]);
	}
	else return "error";
}
int main()
{
	srand((int)time(0));
	string fileName = "words.txt";
	string Word = chooseWord(fileName);
	int l = Word.length();
	char Guess[1000];
	for(int i=0;i<l;i++)
	{
		Guess[i]='_';
		cout << Guess[i];
	}
	cout << endl;
	int Correct=0,attempt=7;
	display_misses(7 - attempt);
	while(Correct!=1 && attempt!=0)
	{
		int cnt=0,wordLeft=0;
		char c;
		cin >> c;
		for(int i=0;i<l;i++)
		{
			if(Word[i]==c)
			{
				cnt++;
				Guess[i]=c;
			}
			if(Guess[i]=='_') wordLeft++;
			cout << Guess[i];
		}
		cout << endl;
		if(cnt==0)
		{
			attempt--;
			cout << "Wrong." << attempt << " attempts remaining." << endl;
			display_misses(7 - attempt);
		}
		if(wordLeft==0)
		{
			Correct=1;
		}
	}
	if(Correct==1)
	{
		cout << "You win!" << " The word is ";
		for(int i=0;i<l;i++)
		{
			cout << Guess[i];
		}
		return 0;
	}
	if(attempt==0)
	{
		cout << "You lose!" << " The word is ";
		for(int i=0;i<l;i++)
		{
			cout << Word[i];
		}
		return 0;
	}
}