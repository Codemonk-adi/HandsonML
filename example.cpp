#include<iostream>
using namespace std;


int main()
{
    cout<<"Welcome to the Hangman program! \nThis program allows the user to play a word guessing game.\n";
     int choice;
     string words [10]={"thailand", "switzerland", "canada", "axolotl", "pangolin", "humuhumunukunukuapuaa","monitor", "memory", "computer", "polymorphism"}; 
    string categories [10]={"country", "country", "country", "rare animals", "rare animals", "rare animals", "IT", "IT", "IT", "IT"};
    cout<< "Please choose a number from 1 to 10: ";
    cin>>choice;
    string secret= words[choice-1];
    string hint = categories[choice-1];
    cout<<"The Selected word belongs to the category: "<<hint<<endl<<endl;
    char input = 'a';
    int guesses = 0;
    int guessed [secret.length()] = {0};
    
    while(input!='0'){
        cout<<"Enter your guess Character (0 to exit):";//exit program?
        cin>>input;
        if(input=='0')
        continue;

        guesses++;
        int correct = 0;
        for(int i=0;i<secret.length();i++){
            if(secret[i] == input){
            guessed[i]=1;
            }
        }
        for(int i=0;i<secret.length();i++){
            if(guessed[i]==1){
            cout<<secret[i];
            correct++;
            }
            else
            cout<<"_";
        }
        
        cout<<endl<<"No. of Guesses:"<<guesses<<endl;
        if(correct == secret.length()){
            input='0';
        } 
    }

    cout<<"The secret word was :"<<secret<<endl;
}
