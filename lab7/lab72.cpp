#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits> // Додано цей заголовок для використання std::numeric_limits

class HelpText {
public:
    void addTerm(const std::string& term, const std::vector<std::string>& explanations) {
        if (explanations.size() < 1 || explanations.size() > 5) {
            std::cerr << "Error: Each term must have between 1 and 5 lines of explanation." << std::endl;
            return;
        }
        helpData[term] = explanations;
    }

    void displayHelp() const {
        for (const auto& entry : helpData) {
            std::cout << "Term: " << entry.first << std::endl;
            for (const auto& line : entry.second) {
                std::cout << line << std::endl;
            }
            std::cout << std::endl;
        }
    }

    void displayExplanation(const std::string& term) const {
        auto it = helpData.find(term);
        if (it != helpData.end()) {
            std::cout << "Term: " << it->first << std::endl;
            for (const auto& line : it->second) {
                std::cout << line << std::endl;
            }
        } else {
            std::cout << "Term not found." << std::endl;
        }
    }

private:
    std::map<std::string, std::vector<std::string>> helpData;
};

void displayMenu() {
    std::cout << "Help System Menu:" << std::endl;
    std::cout << "1. Add Term" << std::endl;
    std::cout << "2. Display Help" << std::endl;
    std::cout << "3. Display Explanation for a Term" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

int main() {
    HelpText helpText;
    int choice;
    std::string term;
    std::vector<std::string> explanations;
    std::string line;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                std::cout << "Enter term: ";
                std::getline(std::cin, term);
                explanations.clear();
                std::cout << "Enter explanation (1 to 5 lines, end with an empty line):" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    std::getline(std::cin, line);
                    if (line.empty()) {
                        break;
                    }
                    explanations.push_back(line);
                }
                helpText.addTerm(term, explanations);
                break;

            case 2:
                helpText.displayHelp();
                break;

            case 3:
                std::cout << "Enter term to explain: ";
                std::getline(std::cin, term);
                helpText.displayExplanation(term);
                break;

            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }
}
