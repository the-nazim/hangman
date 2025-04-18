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
    vector<char> vect_char;
    vector<char> vect_res;
    srand(time(0));
    int random_index = rand() % word_list.size();
    string secret_word = word_list[random_index];
    cout<<"Word: "<<secret_word<<endl;

    for(int i=0; i<secret_word.length(); i++)
        letters[secret_word[i]]++;

    for(int i=0; i<secret_word.length(); i++)
    {    
        vect_char.push_back(secret_word[i]);
        vect_res.push_back('_');
    }
    while(attempt<6)
    {
        cout<<"Guess the letter: ";
        cin>>guess;
        guess_word = "";
        guess_letter[guess]++;
        if((secret_word.find(guess) != string::npos) && (letters[guess]>=guess_letter[guess]))
        {
            cout<<"Correct guess!"<<endl;
            for(int i=0; i<vect_char.size(); i++)
            {
                if((vect_char[i] == guess) && (vect_res[i] == '_'))
                {
                    vect_res[i] = vect_char[i];
                    break;
                }
            }
            for(auto i: vect_res)
            {
                cout<<i<<" ";
                if(i!='_')
                    guess_word += i;   
            }
            cout<<endl;
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