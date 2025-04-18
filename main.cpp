#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    string word;
    file.open("words.txt");
    if (!file)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    vector<string> word_list;

    while (file >> word)
        word_list.push_back(word);

    file.close();
    
    int attempt = 0;
    string guess_word = "";
    char guess;
    map<char, int> letters;
    map<char, int> guess_letter;
    srand(time(0));
    int random_index = rand() % word_list.size();
    string secret_word = word_list[random_index];
    cout<<"Word: "<<secret_word<<endl;

    for(int i=0; i<secret_word.length(); i++)
    {
        letters[secret_word[i]]++;
    }

    while(attempt<6)
    {
        cout<<"Guess the letter: ";
        cin>>guess;
        guess_letter[guess]++;
        if((secret_word.find(guess) != string::npos) && (letters[guess]>=guess_letter[guess]))
        {
            cout<<"Correct guess!"<<endl;
            guess_word += guess;
            cout<<guess_word<<endl;
            if(secret_word == guess_word)
            {
                cout<<"You win!"<<endl;
                break;
            }
        }
        else if((secret_word.find(guess) != string::npos) && (letters[guess]<guess_letter[guess]))
        {
            cout<<"Already guessed!"<<endl;
        }
        else
        {
            cout<<"Wrong guess!"<<endl;
            attempt++;
        }
    }
}