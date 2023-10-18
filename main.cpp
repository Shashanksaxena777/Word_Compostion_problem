#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <iomanip>


using namespace std;

// this part of code checks for the given word is composition of valid words or not
bool check_word_compounded( unordered_set<string>& Word_Dictionary, const string& word)
{
    for (int i = 1; i < word.size(); ++i)
    {
        string first_word = word.substr(0, i);
        string remaining_word = word.substr(i);

        if (Word_Dictionary.count(first_word) && (Word_Dictionary.count(remaining_word) || check_word_compounded(Word_Dictionary, remaining_word)))
        {
            return true;
        }
    }

    return false;
}

// this part of code read content of file and then stores it as required and then perform search operation for finding longest and second longest word
pair<string, string> longest_compound_words(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;        //for error handling
    }
    vector<string> word;
    string line;

    while (getline(file, line))
    {
        word.push_back(line);
    }

    // I Used here lamdba function to sort the collection on size basis...
    sort(word.begin(), word.end(), [](const string& a, const string& b){return a.size() > b.size();});
    unordered_set<string> Word_Dictionary(word.begin(), word.end()); // storing words here to deal with duplicacy

    string First_long_word;
    string second_longest_word;

    for (const string& ch : word)
    {
        if (check_word_compounded(Word_Dictionary, ch))
        {
            if (First_long_word.empty())
            {
                First_long_word = ch;
            } else if (second_longest_word.empty())
            {
                second_longest_word = ch;
                break;
            }
        }
    }

    return make_pair(First_long_word, second_longest_word);
}


int main()
{
    string filename;
    string input1,input2;

    // user choice for selection of files....
    cout<<"Select the files (1 or 2) -->\n";
    cout<<"1. Input_01.txt\n";
    cout<<"2. Input_02.txt\n";
    int n;
    cin>>n;

    switch(n)
    {
        case 1: filename="Input_01.txt";
            break;
        case 2: filename="Input_02.txt";
            break;
        default: cout<<"Invalid option";
    }

    cout<<"\nOutput for Input file ( "<<filename<<" )----->";
    cout<<endl;

// setting up a time from chrono library functionality to calculate the process time. I used here system_clock instead of steady or high resolution clock
    auto start_time = chrono::system_clock::now();
    auto [First_long_word, second_longest_word] = longest_compound_words(filename);
    auto end_time = chrono::system_clock::now();

    // Here I am storing the time point in double type...
    chrono::duration<double> total_time = end_time - start_time;

    cout << fixed << setprecision(6);
    cout << "Longest compound word: " << First_long_word << endl;
    cout << "Second longest compound word: " << second_longest_word << endl;
    cout << "Time taken to process the input file: " << total_time.count()<< " seconds" << endl;

    return 0;
}
