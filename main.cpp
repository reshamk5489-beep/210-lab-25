#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int readCodesToVector(vector<string> &codesVector);
int readCodesToList(list<string> &codesList);
int readCodesToSet(set<string> &codesSet);
void printRightJustified(string text, int width);
int sortVector(vector<string> &codes);
int sortList(list<string> &codes);
int sortSet(set<string> &codes);


int main() {
    vector<string> codesVector;
    list<string> codesList;
    set<string> codesSet;

    int readVectorTime = readCodesToVector(codesVector);
    int readListTime = readCodesToList(codesList);
    int readSetTime = readCodesToSet(codesSet);

    cout << "--" << readSetTime << "--" << endl;
    cout << "Operation    Vector      List       Set" << endl;
    printRightJustified("Read", 9);
    printRightJustified(to_string(readVectorTime), 10); 
    printRightJustified(to_string(readListTime), 10); 
    printRightJustified(to_string(readSetTime), 10); 
    cout << endl;

    int sortVectorTime = sortVector();
    int sortListTime = sortList();
    int sortSetTime = sortSet();

    printRightJustified("Sort", 9);
    printRightJustified(to_string(), 10); 
    printRightJustified(to_string(), 10); 
    printRightJustified(to_string(), 10); 
    cout << endl;

    return 0;
}

int readCodesToVector(vector<string> &codesVector)
{
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codesVector.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000; // converting from milliseconds to microseconds
}

int readCodesToList(list<string> &codesList)
{
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codesList.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000;
}

int readCodesToSet(set<string> &codesSet)
{
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codesSet.insert(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000;
}

void printRightJustified(string text, int width) 
{
    cout << setw(width) << text;
}

int sortVector(vector<string> &codes)
{
    auto start = high_resolution_clock::now();
    
    sort(codes.begin(), codes.end());

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000;
}

int sortList(list<string> &codes)
{
    auto start = high_resolution_clock::now();
    
    codes.sort();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000;
}

int sortSet(set<string> &codes)
{
    auto start = high_resolution_clock::now();

    // no sorting is required for set because item is sorted by default
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000;
}