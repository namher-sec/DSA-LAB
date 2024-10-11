#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Input file name
    std::string inputFile = "input.txt";

    // Output file name
    std::string outputFile = "output.txt";

    // Open input file
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFile << std::endl;
        return 1;
    }

    // Open output file
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFile << std::endl;
        return 1;
    }

    // Read input file and calculate average scores
    std::string name;
    double midterm1, midterm2, finalExam, average;
    while (inFile >> name >> midterm1 >> midterm2 >> finalExam) {
        average = 0.25 * midterm1 + 0.25 * midterm2 + 0.5 * finalExam;
        outFile << name << " " << midterm1 << " " << midterm2 << " " << finalExam << " " << average << std::endl;
    }

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}
