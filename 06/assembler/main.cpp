#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
#include<iostream>
#include<regex>
using std::ofstream;
using std::endl;
using std::cout;
std::string decimalToBinary(std::string decimalString) {
    int decimalValue = std::stoi(decimalString);
    std::bitset<16> binaryValue(decimalValue);
    std::string binaryString = binaryValue.to_string();
    size_t pos = binaryString.find('1');
    if (pos != std::string::npos) {
        binaryString = binaryString.substr(pos);
    } else {
        binaryString = "0";
    }
    while (binaryString.size() < 16) {
        binaryString.insert(0, "0");
    }
    return binaryString;
}
int main(int argc,char *argv[]){
    string inputFileName=argv[1];
    string outputFileName=inputFileName.substr(0,inputFileName.length()-4)+".hack";
    //std::cout<<argc;
    if(argc==2){
        Parser parser(inputFileName);
        SymbolTable symbolTable;
        Code code;
        string symbol,comp,jump,dest,compBin,jumpBin,destBin;
        int symbolBin;
        ofstream fout;
        fout.open(outputFileName);
        while(true){
            if(!parser.hasMoreCommands()){
                break;
            }
            if(parser.commandType()=='t'){
                string tage=parser.tage();
                symbolTable.addEntry(tage,parser.codeLine);
            }
            parser.advance();
        }
        parser.reset();

        while(true){
            if(!parser.hasMoreCommands()){
                break;
            }
            if(parser.commandType()=='a'){
               // cout<<"a "<<parser.codeLine<<" "<<parser.thisLine()<<endl;
                std::regex e("^[0-9]*$");
                symbol=parser.symbol();
                if(regex_match(symbol,e)){//如果只是数字
                    fout<<decimalToBinary(symbol)<<endl;
                }else{
                    if(symbolTable.contains(symbol)){//如果是标识符
                        symbolBin=symbolTable.GetAddress(symbol);
                        fout<<decimalToBinary(std::to_string(symbolBin))<<endl;
                    }else{//如果是变量
                        symbolTable.addEntry(symbol,symbolTable.variableNumber);
                        fout<<decimalToBinary(std::to_string(symbolTable.variableNumber))<<endl;
                        symbolTable.variableNumber++;
                    }
                }
            }else if(parser.commandType()=='c'){            
                dest=parser.dest();
                comp=parser.comp();
                jump=parser.jump();
                destBin=code.dest(dest);
                compBin=code.comp(comp);
                jumpBin=code.jump(jump);
                fout<<"111"<<compBin<<destBin<<jumpBin<<endl;
            }
            parser.advance();
        }
    }
}