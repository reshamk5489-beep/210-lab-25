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
int insertVector(vector<string> &codesVector);
int insertList(list<string> &codesList);
int insertSet(set<string> &codesSet);
int deleteVector(vector<string> &codesVector);
int deleteList(list<string> &codesList);
int deleteSet(set<string> &codesSet);

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

    int sortVectorTime = sortVector(codesVector);
    int sortListTime = sortList(codesList);
    int sortSetTime = sortSet(codesSet);

    printRightJustified("Sort", 9);
    printRightJustified(to_string(sortVectorTime), 10); 
    printRightJustified(to_string(sortListTime), 10); 
    printRightJustified(to_string(sortSetTime), 10); 
    cout << endl;

    int insertVectorTime = insertVector(codesVector);
    int insertListTime = insertList(codesList);
    int insertSetTime = insertSet(codesSet);

    printRightJustified("Insert", 9);
    printRightJustified(to_string(insertVectorTime), 10); 
    printRightJustified(to_string(insertListTime), 10); 
    printRightJustified(to_string(insertSetTime), 10); 
    cout << endl;

    int deleteVectorTime = deleteVector(codesVector);
    int deleteListTime = deleteList(codesList);
    int deleteSetTime = deleteSet(codesSet);

    printRightJustified("Delete", 9);
    printRightJustified(to_string(deleteVectorTime), 10); 
    printRightJustified(to_string(deleteListTime), 10); 
    printRightJustified(to_string(deleteSetTime), 10); 
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
    auto duration = duration_cast<microseconds>(end - start);

    fin.close();

    return duration.count();
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
    auto duration = duration_cast<microseconds>(end - start);

    fin.close();

    return duration.count();
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
    auto duration = duration_cast<microseconds>(end - start);

    fin.close();

    return duration.count();
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
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int sortList(list<string> &codes)
{
    auto start = high_resolution_clock::now();
    
    codes.sort();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int sortSet(set<string> &codes)
{
    // no sorting is required for set because item is sorted by default so returning -1
    return -1;
}

int insertVector(vector<string> &codesVector)
{
    auto start = high_resolution_clock::now();
    
    codesVector.insert(codesVector.begin() + 10000, "TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int insertList(list<string> &codesList)
{
    auto start = high_resolution_clock::now();
    
    auto it = next(codesList.begin(), 10000);
    codesList.insert(it, "TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int insertSet(set<string> &codesSet)
{
    auto start = high_resolution_clock::now();
    
    codesSet.insert("TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteVector(vector<string> &codesVector)
{
    auto start = high_resolution_clock::now();
    
    codesVector.erase(codesVector.begin() + 10000);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteList(list<string> &codesList)
{
    auto start = high_resolution_clock::now();
    
    auto it = next(codesList.begin(), 10000);
    codesList.erase(it);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteSet(set<string> &codesSet)
{
    auto start = high_resolution_clock::now();
    
    auto it = next(codesSet.begin(), 10000);
    codesSet.erase(it);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}