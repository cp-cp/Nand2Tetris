#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
//using namespace std;
using std::string;
using std::map;
//using std::unordered_map;
class Code
{
    public:
        Code();
        string dest(string destMnemonics);
        string comp(string compMnemonics);
        string jump(string jumpMnemonics);
    private:
        map<string,string>destTable;
        map<string,string>compTable;
        map<string,string>jumpTable;
};