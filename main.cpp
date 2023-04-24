#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;
//LINES 8-36 ARE THE ORIGINAL CODE
/*
void ReadWords(string words[], int numWords);
int main()
{
    int numWords = 15;
    string words[numWords];

    return 0;
}
void Play(string words[], int numWords){

}
void ReadWords(string words[], int numWords){
    ifstream infile;
    infile.open("words.txt");
    if(!infile)
        cout<<"Could not open file"<<endl;
    else{
        for(int i=0; i<numWords; i++)
            infile>>words[i];
    }
    infile.close();
}
void PressKeyToContinue(){
    string x;
    cout<<"Press any key to continue:";
    cin>>x;
}*/



void ReadWords(string words[], int numWords);
void Play(string words[], int numWords);

int main()
{
    int numWords = 15;
    string words[numWords];
    ReadWords(words, numWords);
    Play(words,numWords);

    return 0;
}

void PrintWithSpaces(const string& str)
{
    for (int j = 0; j < str.size(); j++)
    {
        cout << str[j] << " ";
    }
    cout << endl;
}

void Play(string words[], int numWords)
{

    int lives = 5;
    cout << endl;

    for(int i=0; i < numWords && lives > 0; i++)
    {
        string& hiddenWord = words[i];
        string guessWord(hiddenWord.size(), ' ');
        string underline(hiddenWord.size(), '-');
        string lettersUsed;


        while (true)
        {
            //print status (guess lives and letters used)
            PrintWithSpaces(guessWord);
            PrintWithSpaces(underline);
            cout << "Lives: " << lives << endl;
            cout << "Letters Used: ";
            PrintWithSpaces(lettersUsed);

            //get input character
            cout << "Enter Letter: ";
            char input;
            cin >> input;
            cout << endl;

            //update game state
            lettersUsed.push_back(input); //keeps track and adds to list of letters used
            bool lostLife = true;
            for (int j = 0; j < hiddenWord.size(); j++)
            {
                if (hiddenWord[j] == input)
                {
                    lostLife = false;
                    guessWord[j] = input;
                }

            }

            if(hiddenWord == guessWord)
            {
                cout << "You win! Next word." << endl;
                break;
            }

            if (lostLife)
            {
                lives--;
            }
            else
            {
                lives++;
            }

            if (lives == 0)
            {
                cout << "You lose!" << endl;
                break;
            }
        }
    }
}





void ReadWords(string words[], int numWords)
{
    ifstream infile;
    infile.open("words.txt", ios::in);
    if(!infile)
        cout<<"Could not open file"<<endl;
    else
    {
        for(int i=0; i<numWords; i++)

            infile>>words[i];
    }

    infile.close();
}

void PressKeyToContinue()
{
    string x;
    cout<<"Press any key to continue:";
    cin>>x;
}



