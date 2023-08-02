#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

/**
 * @brief Gets the number of scores from the user.
 * 
 * @param size Reference to store the number of scores entered by the user.
 */
void getVectorSize(int& size);

/**
 * @brief Reads the high scores data from the user.
 * 
 * @param scores Reference to the vector to store the high scores data.
 */
void readData(vector<Highscore>& scores);

/**
 * @brief Sorts the high scores data in descending order based on scores.
 * 
 * @param scores Reference to the vector containing the high scores data to be sorted.
 */
void sortData(vector<Highscore>& scores);

/**
 * @brief Finds the iterator of the largest score within a given range.
 * 
 * @param startingLocation Iterator pointing to the starting position of the range.
 * @param endingLocation Iterator pointing to the ending position of the range (exclusive).
 * @return Iterator pointing to the element with the largest score within the range.
 */
vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation
);

/**
 * @brief Displays the sorted high scores data.
 * 
 * @param scores Reference to the vector containing the high scores data to be displayed.
 */
void displayData(const vector<Highscore>& scores);

int main() {
    vector<Highscore> highScores;
    int size;

    getVectorSize(size);
    highScores.resize(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);

    return 0;
}

void getVectorSize(int& size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}

void readData(vector<Highscore>& scores) {
    for (size_t index = 0; index < scores.size(); index++) {
        cout << "Enter the name for score #" << (index + 1) << ": ";
        cin.getline(scores[index].name, MAX_NAME_SIZE, '\n');

        cout << "Enter the score for score #" << (index + 1) << ": ";
        cin >> scores[index].score;
        cin.ignore();
    }
}

void sortData(vector<Highscore>& scores) {
    for (auto iter = scores.begin(); iter != scores.end() - 1; iter++) {
        swap(*findLocationOfLargest(iter, scores.end()), *iter);
    }
}

vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation
) {
    auto iterOfLargest = startingLocation;
    for (auto iter = startingLocation + 1; iter != endingLocation; iter++) {
        if (iter->score > iterOfLargest->score) {
            iterOfLargest = iter;
        }
    }
    return iterOfLargest;
}

void displayData(const vector<Highscore>& scores) {
    cout << "Top Scorers: " << endl;
    for (auto iter = scores.begin(); iter != scores.end(); iter++) {
        cout << iter->name << ": " << iter->score << endl;
    }
}
