#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
using namespace std;

int readCodesToVector();
int readCodesToList();
int readCodesToSet();

int main() {
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

int readCodesToVector()
{
    ifstream fin("Codes.txt");
    vector<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    return 0;
}

int readCodesToList()
{
    ifstream fin("Codes.txt");
    list<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    return 0;
}