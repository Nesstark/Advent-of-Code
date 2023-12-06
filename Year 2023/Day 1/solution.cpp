#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int getCalibrationValue(const std::string& line) {
    // Find the first and last digits in the line
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

    // Combine the digits to form a two-digit number
    int calibrationValue = (firstDigit - '0') * 10 + (lastDigit - '0');
    return calibrationValue;
}

int calculateCalibrationSum(const std::string& calibrationDocument) {
    std::istringstream iss(calibrationDocument);
    std::string line;
    int sum = 0;

    // Iterate through each line in the document
    while (std::getline(iss, line)) {
        int calibrationValue = getCalibrationValue(line);
        sum += calibrationValue;
    }

    return sum;
}

int main() {
    // Read the calibration document from a file or any other source
    std::ifstream file();
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string calibrationDocument = buffer.str();

    // Calculate the sum of calibration values
    int sum = calculateCalibrationSum(calibrationDocument);

    // Display the result
    std::cout << "The sum of all calibration values is: " << sum << std::endl;

    return 0;
}
