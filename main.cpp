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
    {
        word_list.push_back(word);
    }
    file.close();
    srand(time(0));
    int random_index = rand() % word_list.size();
    // cout<<"Random word: "<<word_list[random_index]<<endl;
    string secret_word = word_list[random_index];
    cout<<"Word: "<<secret_word<<endl;
    int attempt = 0;
    string guess = "";
    string guess_word = "";
    while(attempt<6)
    {
        cout<<"Guess the letter: ";
        cin>>guess;
        if(secret_word.find(guess) != string::npos)
        {
            cout<<"Correct guess!"<<endl;
            guess_word += guess;
            if(secret_word == guess_word)
            {
                cout<<"You win!"<<endl;
                break;
            }
        }
        else
        {
            cout<<"Wrong guess!"<<endl;
            attempt++;
        }
    }

}