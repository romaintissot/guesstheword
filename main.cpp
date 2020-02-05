#include <iostream>
#include <ctime>
#include <cstdlib>



using namespace std;
string  mixedWord(string word);

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

    cout << "Hello player 1, please choose a word :"<<endl;
    cin>>initialWord;

    cout << "Hello player 2, guess the word : "<<mixedWord(initialWord)<<endl;
    do{

        cin>>tryWord;
    if (tryWord == initialWord)
      {
         cout << "Congrats! you found it :)"<<endl;
      }
      else
      {
         cout << "wrong, sorry. Try again : "<<mixedWord(initialWord)<<endl;
      }
    }while(tryWord != initialWord);

    return 0;
}

