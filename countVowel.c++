#include <iostream>
#include <string>

int countVowels(const std::string& str) {
    std::string vowels = "aeiouAEIOU";  // String containing all vowels (both cases)
    int vowelCount = 0;
    
    // Loop through each character in the input string
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];  // Current character in the string
        
        // Check if the current character is a vowel
        for (size_t j = 0; j < vowels.length(); ++j) {
            if (ch == vowels[j]) {
                ++vowelCount;
                break;  // Break inner loop if vowel is found
            }
        }
    }
    
    return vowelCount;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);  // Read the entire line of input

    int result = countVowels(input);
    std::cout << "Number of vowels: " << result << std::endl;

    return 0;
}
