#include "SymbolTable.h"

SymbolTable::SymbolTable(){
    symbolTable["SP"] = 0;
    symbolTable["LCL"] = 1;
    symbolTable["ARG"] = 2;
    symbolTable["THIS"] = 3;
    symbolTable["THAT"] = 4;
    symbolTable["R0"] = 0;
    symbolTable["R1"] = 1;
    symbolTable["R2"] = 2;
    symbolTable["R3"] = 3;
    symbolTable["R4"] = 4;
    symbolTable["R5"] = 5;
    symbolTable["R6"] = 6;
    symbolTable["R7"] = 7;
    symbolTable["R8"] = 8;
    symbolTable["R9"] = 9;
    symbolTable["R10"] = 10;
    symbolTable["R11"] = 11;
    symbolTable["R12"] = 12;
    symbolTable["R13"] = 13;
    symbolTable["R14"] = 14;
    symbolTable["R15"] = 15;
    symbolTable["SCREEN"] = 16384;
    symbolTable["KBD"] = 24576;
}

bool SymbolTable::contains(string symbol){    
    map<string,int>::iterator it;
    it=symbolTable.find(symbol);
    //std::cout<<"&"<<symbol<<":"<<" "<<symbolTable.size()<<std::endl;
    if(symbolTable.find(symbol)!=symbolTable.end()){
        return true;
    }
    else{
        return false;
    }
}
void SymbolTable::addEntry(string symbol,int address){
    if(!contains(symbol))
        symbolTable[symbol]=address;
        //symbolTable.insert(make_pair(symbol,address));
}
int SymbolTable::GetAddress(string symbol){
    map<string,int>::iterator it;
    it=symbolTable.find(symbol);
    if(it!=symbolTable.end()){
        return it->second;
    }
    else{
        return -1;
    }
}
