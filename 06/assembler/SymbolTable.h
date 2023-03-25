#include<map>
#include<iostream>
using std::map;
using std::string;
class SymbolTable{
    public:
        SymbolTable();//构造函数
        void addEntry(string symbol,int address);//添加符号
        bool contains(string symbol);
        int GetAddress(string symbol);
        int variableNumber=16;
    private:
        map<string,int>symbolTable;
};