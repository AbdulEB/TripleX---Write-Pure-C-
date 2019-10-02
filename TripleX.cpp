#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
     // Print welcome messages to the terminal cl main.cpp /EHsc
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room....\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    //Print CodeSum and CodeProduct to the terminal
    std::cout << "There are three numbers in the code\n";
    std::cout << "The code add up to: " << CodeSum;
    std::cout << "\nThe product of the code: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC;

    //Store Players guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nYou win!\n crack the file, move the next level\n\n";
        return true;
    }
    else {
        std::cout << "\nYou entered the wrong code! Please try again.\n\n";
        return false;
    }

}

int main()
{
    srand(time(NULL));// create new random sequence of time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (MaxDifficulty >= LevelDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}