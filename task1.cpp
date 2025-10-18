#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Needed for std::numeric_limits

// Function Prototypes
void displayMenu();
void writeFile();
void readFile();
void appendFile();
void clearInputBuffer();

/**
 * @brief Clears the input buffer to prevent issues with mixed input (e.g., int followed by getline).
 */
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Displays the application menu.
 */
void displayMenu() {
    std::cout << "\n--- CODTECH File Management Tool ---\n";
    std::cout << "1. Write/Overwrite Data to File\n";
    std::cout << "2. Read Data from File\n";
    std::cout << "3. Append Data to File\n";
    std::cout << "4. Exit\n";
}

/**
 * @brief Writes data to a file. Uses std::ofstream which OVERWRITES by default.
 */
void writeFile() {
    std::string fileName;
    std::string content;

    std::cout << "Enter the filename (e.g., document.txt): ";
    std::getline(std::cin, fileName);

    std::cout << "Enter the content to WRITE (WARNING: This will OVERWRITE the file):\n";
    std::getline(std::cin, content);

    // std::ofstream: Output file stream. Opens file for writing.
    std::ofstream outFile(fileName);

    if (outFile.is_open()) {
        outFile << content << "\n";
        std::cout << " Success: Data successfully wrote to '" << fileName << "'.\n";
        outFile.close(); // Close the stream
    } else {
        std::cerr << " Error: Could not open file '" << fileName << "' for writing.\n";
    }
}

/**
 * @brief Reads and displays the content of a file.
 */
void readFile() {
    std::string fileName;
    std::string line;

    std::cout << "Enter the filename to READ (e.g., document.txt): ";
    std::getline(std::cin, fileName);

    // std::ifstream: Input file stream. Opens file for reading.
    std::ifstream inFile(fileName);

    if (inFile.is_open()) {
        std::cout << "\n--- Content of '" << fileName << "' ---\n";
        // Read file line-by-line until the end
        while (std::getline(inFile, line)) {
            std::cout << line << '\n';
        }
        std::cout << "-----------------------------------\n";
        inFile.close(); // Close the stream
    } else {
        std::cerr << " Error: File '" << fileName << "' not found or could not be opened for reading.\n";
    }
}

/**
 * @brief Appends new data to the end of an existing file.
 */
void appendFile() {
    std::string fileName;
    std::string content;

    std::cout << "Enter the filename (e.g., document.txt): ";
    std::getline(std::cin, fileName);

    std::cout << "Enter the content to APPEND:\n";
    std::getline(std::cin, content);

    // std::ofstream with std::ios::app flag: opens the file for writing at the end.
    std::ofstream appendFile(fileName, std::ios::app);

    if (appendFile.is_open()) {
        // Add a newline before the new content for clear separation in the file
        appendFile << "\n" << content;
        std::cout << " Success: Data successfully appended to '" << fileName << "'.\n";
        appendFile.close(); // Close the stream
    } else {
        std::cerr << " Error: Could not open file '" << fileName << "' for appending.\n";
    }
}

/**
 * @brief Main execution function.
 */
int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";

        // Basic input validation loop
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // Reset error flags
            clearInputBuffer();
        }
        clearInputBuffer(); // Clear buffer remaining newline character

        switch (choice) {
            case 1:
                writeFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendFile();
                break;
            case 4:
                std::cout << " Exiting the File Management Tool. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please select 1, 2, 3, or 4.\n";
        }
        std::cout << "\n========================================\n";
    } while (choice != 4);

    return 0;

}
