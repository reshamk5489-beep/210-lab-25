#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int readCodesToVector();
int readCodesToList();
int readCodesToSet();
void printRightJustified(string text, int width);
int sortVector(vector<string> &codes);
int sortList(list<string> &codes);
int sortSet(set<string> &codes);


int main() {
    int readVectorTime = readCodesToVector();
    int readListTime = readCodesToList();
    int readSetTime = readCodesToSet();

    cout << "--" << readSetTime << "--" << endl;
    cout << "Operation    Vector      List       Set" << endl;
    printRightJustified("Read", 9);
    printRightJustified(to_string(readVectorTime), 10); 
    printRightJustified(to_string(readListTime), 10); 
    printRightJustified(to_string(readSetTime), 10); 
    cout << endl;

    printRightJustified("Sort", 9);
    printRightJustified(to_string(readVectorTime), 10); 
    printRightJustified(to_string(readListTime), 10); 
    printRightJustified(to_string(readSetTime), 10); 
    cout << endl;

    return 0;
}

int readCodesToVector()
{
    ifstream fin("Codes.txt");
    vector<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000; // converting from milliseconds to microseconds
}

int readCodesToList()
{
    ifstream fin("Codes.txt");
    list<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000;
}

int readCodesToSet()
{
    ifstream fin("Codes.txt");
    set<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.insert(code);
    }
4
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
    
    sort(codes.begin(), codes.end(), greater<int>());

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