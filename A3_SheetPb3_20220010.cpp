#include <bits/stdc++.h>
using namespace std;

class FreqTable
{
    map<string, int> freq_table;
    static string cleanWord(const string &word)
    {
        string cleaned = "";
        for (char c : word)
            if (isalnum(c) || c == '-')
                cleaned += tolower(c);
        return cleaned;
    }

public:
    FreqTable() = default;
    void addWord(const string &word)
    {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty())
            freq_table[cleanedWord]++;
    }
    void displayTable() const
    {
        cout << "Frequence Table:\n";
        for (const auto &entry : freq_table)
            cout << entry.first << ": " << entry.second << "times\n";
    }
};

int main()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Error opening file: " + filename + '\n';
        return 1;
    }

    FreqTable table;
    string word;
    while (inputFile >> word)
        table.addWord(word);
    table.displayTable();
}