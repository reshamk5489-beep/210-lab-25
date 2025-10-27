#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int readCodesToVector();
int readCodesToList();
int readCodesToSet();

int main() {
    readCodesToVector();
    readCodesToList();
    readCodesToSet();

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
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    vector<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    cout << "Vector size: " << codes.size() << endl;
    cout << "Vector[0]: " << codes[0] << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}

int readCodesToList()
{
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    list<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    cout << "List size: " << codes.size() << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}

int readCodesToSet()
{
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    set<string> codes;
    string code;

    while (fin >> code)
    {
        codes.insert(code);
    }

    fin.close();

    cout << "Set size: " << codes.size() << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count();
}