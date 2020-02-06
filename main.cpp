#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>



using namespace std;
string  mixedWord(string word);
int life;
string again;
ifstream dico;



string mixedWord(string word)
{
    int randomNumber(0);
    string newWord;

    while (word.size() != 0)
    {
            randomNumber = rand() % word.size();
            newWord+=word[randomNumber];
            word.erase(randomNumber,1);

    }
    return newWord;
}



int main()
{
    srand(time(0));
    string initialWord;
    string tryWord;
    string line;
    int player;
    int total;
    int randomLine;
    int count;

    do{
        cout<<"How many players ?(1/2)"<<endl;
        cin>>player;
        if(player == 1){
            dico.open("dico.txt");
            total = 0;
            count = 0;
            if (dico.fail()){
                cout<<"Error, opening file impossible"<<endl;
            }

            while(!dico.eof()){
                dico>>line;
                total++;
            }
            randomLine = rand() % total;
            cout<<"nombre de lignes "<<total<<endl;
            cout<<"ligne au hasard "<<randomLine<<endl;
            dico.seekg(0, ios::beg);
            while (count!=randomLine){
                dico>>line;
                count++;
            }
            cout<<"mot "<<line<<endl;
            cout<<"ligne choisie "<<count<<endl;
            initialWord = line;
            dico.close();
        }else{
        cout << "Hello player 1, please choose a word :"<<endl;
        cin>>initialWord;
        }
        life = 5;
        cout << "Hello player 2, guess the word : "<<mixedWord(initialWord)<<endl;
            do{

                cin>>tryWord;
            if (tryWord == initialWord)
              {
                 cout << "Congrats! you found it :)"<<endl;
              }
              else
              {
                 life--;
                 cout << "wrong, sorry. "<<life<<" lives left. Try again : "<<mixedWord(initialWord)<<endl;

              }
            }while(tryWord != initialWord && life!=0);
            if(life == 0){
                cout<<"Game over... The solution was "<<initialWord<<". Play again ? (Y/N)"<<endl;
                cin>>again;
            }else{
            cout<<"Do you want to play again ? (Y/N)"<<endl;
            cin>>again;
            }
    }while(again == "Y");

    return 0;
}

