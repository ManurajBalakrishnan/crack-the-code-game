#include<iostream>
#include<ctime> 

using namespace std;

void PrintIntroduction(int Difficulty)
{
    // printing the welcome message to the terminal
    cout << "\n\nYou are a Hacker cracking the computer " << Difficulty ;
    cout << " computer pin....\nEnter the correct codes to continue....\n\n";

}

//function
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty, CodeB = rand() % Difficulty + Difficulty, CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;    
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print the CodeSum and CodeProduct to the terminal
    cout << "+ There are 3 numbers in the code \n";
    cout << "+ The codes add-up to: " << CodeSum << "\n";
    cout << "+ The codes multiply to give: " << CodeProduct << "\n" ;
    
    int GuessA,GuessB,GuessC;
    
    //getting the input from the user
    cin >> GuessA >> GuessB >> GuessC; 

    int GuessSum = GuessA +GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
     
    // check if the player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        cout << "\nGood work.. you are Moving to the next level you cracked the computer " << Difficulty << "...keep going*** "; 
        return true;
    }
    else 
    {
        cout << "\nyou have entered the wrong code hacker....Try again***";
        return false;
    }
}



int main()
{
    srand(time(NULL)); //creates new random sequence based on time of the day
    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) //loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //clears any error
        cin.ignore(); //Discord the buffer

        if (bLevelComplete)
        { //increase the level difficulty
            ++LevelDifficulty;

        }
        
    }

    cout << "\nWow Great work.... You won the game....!";
    return 0;
}