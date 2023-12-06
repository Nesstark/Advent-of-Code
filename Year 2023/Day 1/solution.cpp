#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int getCalibrationValue(const std::string& line) {
    char firstDigit = '0';
    char lastDigit = '0';
    for (char ch : line) {
        if (isdigit(ch)) {
            if (firstDigit == '0') {
                firstDigit = ch;
            }
            lastDigit = ch;
        }
    }

    int calibrationValue = (firstDigit - '0') * 10 + (lastDigit - '0');
    return calibrationValue;
}

int calculateCalibrationSum(const std::string& calibrationDocument) {
    std::istringstream iss(calibrationDocument);
    std::string line;
    int sum = 0;

    while (std::getline(iss, line)) {
        int calibrationValue = getCalibrationValue(line);
        sum += calibrationValue;
    }

    return sum;
}

int main() {
    std::ifstream file("/Users/emilmadsen/Library/CloudStorage/OneDrive-Personligt/Personlig/Advent-of-Code/Year 2023/Day 1/input");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string calibrationDocument = buffer.str();

    int sum = calculateCalibrationSum(calibrationDocument);

    std::cout << "The sum of all calibration values is: " << sum << std::endl;

    return 0;
}
