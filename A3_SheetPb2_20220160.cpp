#include <bits/stdc++.h>
using namespace std;
class StringSet {
private:
    set<string> words;

public:
    // Constructor from file
    StringSet(ifstream& file) {
        loadFromFile(file);
    }

    // Constructor from string
    StringSet(const string& text) {
        loadFromString(text);
    }

    // Load words from file
    void loadFromFile(ifstream& file) {

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                processLine(line);
            }
        }
    }

    // Load words from string
    void loadFromString(const string& text) {
        istringstream iss(text);
        string word;
        while (iss >> word) {
            processWord(word);
        }
    }

    // Add a word to the set
    void addWord(const string& word) {
        processWord(word);
    }

    // Remove a word from the set
    void removeWord(const string& word) {
        words.erase(word);
    }

    // Clear the set
    void clearSet() {
        words.clear();
    }

    // Return the number of strings in the set
    int size() const {
        return words.size();
    }

    // Output all strings in the set
    void printSet() const {
        for (const auto& word : words) {
            cout << word << " ";
        }
        cout << endl;
    }

    // Overload + operator to return the union of two StringSet objects
    StringSet operator+(const StringSet& other) const {
        StringSet result = *this;
        result.words.insert(other.words.begin(), other.words.end());
        return result;
    }

    // Overload * operator to return the intersection of two StringSet objects
    StringSet operator*(StringSet& other) {
        string result;
        for (const auto& word : words) {
            if (other.words.count(word) > 0) {
                result+=word+' ';
            }
        }
        return StringSet(result);
    }

    // Compute similarity between two StringSet objects
    double computeSimilarity(StringSet& other) {
        StringSet intersectionSet(*this * other);
        int intersectionSize = intersectionSet.size();
        int setSize = size();
        int otherSize = other.size();

        if (setSize == 0 || otherSize == 0) {
            return 0.0;  // To avoid division by zero
        }

        double similarity = static_cast<double>(intersectionSize) /
                            (sqrt(static_cast<double>(setSize)) * sqrt(static_cast<double>(otherSize)));

        return similarity;
    }

private:
    // Helper function to process a line of text
    void processLine(const string& line) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            processWord(word);
        }
    }

    // Helper function to process a word
    void processWord(const string& word) {
        // Convert to lowercase and remove punctuation
        string processedWord;
        for (char ch : word) {
            if (isalpha(ch)) {
                processedWord += tolower(ch);
            }
        }
        if (!processedWord.empty()) {
            words.insert(processedWord);
        }
    }
};

int main() {

    ifstream file(R"(C:\Users\Seif Eldin\OneDrive\Desktop\FCAI\oop\opppp\text.txt)");
    // Test the class and functions
    StringSet set1("This is a sample document.");
    StringSet set2(file);

    cout << "Set 1: ";
    set1.printSet();
    cout << "Set 2: ";
    set2.printSet();

    StringSet unionSet = set1 + set2;
    cout << "Union Set: ";
    unionSet.printSet();

    StringSet intersectionSet = set1 * set2;
    cout << "Intersection Set: ";
    intersectionSet.printSet();

    double similarity = set1.computeSimilarity(set2);
    cout << "Similarity between Set 1 and Set 2: " << similarity << endl;

    return 0;
}
