#include "Parser.h"
#include<regex>
using namespace std;
Parser::Parser(const string& filename){
    std::ifstream infile(filename);
    if (!infile.is_open()) { // 检查文件是否成功打开
        std::cout << "Unable to open file " << filename << "\n";
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
	    // size_t lPos = line.find_first_not_of(' ');
	    // int rPos = line.find_last_not_of(' ');
        // if(rPos!=string::npos)
        //     line=line.substr(0,rPos+1);
        // if(lPos!=string::npos)
        //     line=line.substr(lPos);
        int index = 0;
        if (!line.empty()) {
            //string::npos 表示查找没有匹配
            while((index = line.find(' ', index)) != string::npos) {
                line.erase(index, 1);
            }
        }//去除空格
        size_t pos=line.find("//");
        if(pos!=string::npos)
             line=line.substr(0,pos);
        //去除注释
        lines.push_back(line);
    }
    infile.close();
}
bool Parser::hasMoreCommands(){
    if(currentLine<lines.size()){
        return true;
    }else{
        return false;
    }
}
void Parser::advance(){
    if(hasMoreCommands())
    {
        currentLine++;
        char codetype=commandType();
        if(codetype=='a'||codetype=='c')codeLine++;
    }
}
char Parser::commandType(){
    string line=lines[currentLine];
    std::regex re("^\\s*$");
    std::regex_match(line, re);
    if(line[0]=='@')return 'a';//A指令
    else if((line[0]=='/'&&line[1]=='/')||(std::regex_match(line, re)))return 'z';//注释
    else if(line[0]=='(')return 't';
    else return 'c';
}//无自定义符号
string Parser::symbol(){
    string line=lines[currentLine];
    return line.substr(1);
}
string Parser::dest(){
    string line=lines[currentLine];
    size_t pos=line.find("=");
    if(pos!=string::npos)
    {
        return line.substr(0,pos);
    }
    return "";
}
string Parser::comp(){
    string line=lines[currentLine];
    size_t pos1=line.find("=");
    size_t pos2=line.find(";");
    size_t pos3=line.find_first_of(" ",pos1);
    size_t pos4=line.find("/");
    if(pos1!=string::npos)
    {
        if(pos2!=string::npos)
            return line.substr(pos1+1,pos2-pos1+1);
        else
            if(pos3!=string::npos)
            {
                cout<<"hihihihi:"<<pos3<<" "<<pos1<<endl;
                return line.substr(pos1+1,pos3-pos1+1);
            }
            else if(pos4!=string::npos)
                return line.substr(pos1+1,pos4-pos1+1);
                else return line.substr(pos1+1);
    }
    else{
        return line.substr(0,pos2);
    }
}
string Parser::jump(){
    string line=lines[currentLine];
    size_t pos=line.find(";");
    if(pos!=string::npos){
        return line.substr(pos+1,3);
    }
    return "";
}
string Parser::thisLine(){
    return lines[currentLine];
}
string Parser::tage(){
    string line=lines[currentLine];
	int lPos = line.find_first_not_of('(');
	int rPos = line.find_last_not_of(')');
	return line.substr(lPos, rPos - lPos + 1);
}
void Parser::reset(){
    currentLine=0;
    codeLine=0;
}