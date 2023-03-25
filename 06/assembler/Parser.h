#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using std::string;
class Parser{
    public:
        Parser(const string& filename);
        bool hasMoreCommands();
        void advance();
        char commandType();
        string symbol();
        string dest();
        string comp();
        string jump();
        string tage();
        string thisLine();
        void reset();
        int codeLine=0;
        int currentLine=0;
        //~Parser();
    private:
        std::vector<string>lines;
        /* data */
};

