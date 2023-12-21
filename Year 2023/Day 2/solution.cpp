#include <iostream>;
#include <sstream>;
#include <vector>;
#include <string>;

int main() {
    // Define the target cube counts
    int targetRed = 12;
    int targetGreen = 13;
    int targetBlue = 14;

    // Define the puzzle input
    std::vector<std::string> games = {
        "1 green, 2 red, 6 blue; 4 red, 1 green, 3 blue; 7 blue, 5 green; 6 blue, 2 red, 1 green",
        // ... (paste the rest of the puzzle input here)
    };

    int sumOfPossibleGames = 0;

    // Iterate through each game
    for (int i = 0; i < games.size(); ++i) {
        // Parse the game string and count the cubes
        std::istringstream iss(games[i]);
        std::string subset;
        int redCount = 0, greenCount = 0, blueCount = 0;

        while (getline(iss, subset, ';')) {
            std::istringstream subsetIss(subset);
            std::string color;
            int count;

            while (subsetIss >> count >> color) {
                if (color == "red") {
                    redCount += count;
                } else if (color == "green") {
                    greenCount += count;
                } else if (color == "blue") {
                    blueCount += count;
                }
            }
        }

        // Check if the game is possible
        if (redCount == targetRed && greenCount == targetGreen && blueCount == targetBlue) {
            std::cout << "Game " << (i + 1) << " is possible." << std::endl;
            sumOfPossibleGames += (i + 1);
        }
    }

    // Output the sum of IDs of possible games
    std::cout << "Sum of IDs of possible games: " << sumOfPossibleGames << std::endl;

    return 0;
}
