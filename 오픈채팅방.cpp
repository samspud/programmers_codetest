#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> id_to_nickname;

vector<string> split(string a, char delimiter){
    
    vector<string> split_string;
    
    string aa = "";
    for(char & c : a){        
        if(c == delimiter){
            split_string.push_back(aa);
            aa = "";
        } else{
            aa += c;
        }
    }
    
    split_string.push_back(aa);
    
    return split_string;
}


string getNickName(string uid){
    return id_to_nickname[uid];
}

void initialize(vector<string>& record){
    for(string & line : record){
        vector<string> split_line = split(line, ' ');
        
        if(split_line.size() >= 3){
            id_to_nickname[split_line[1]] = split_line[2];
        }
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    initialize(record);
    
    for(string & l : record){
        vector<string> split_l = split(l, ' ');
        if(split_l[0] == "Enter"){
            answer.push_back(id_to_nickname[split_l[1]] + "님이 들어왔습니다.");
        } else if(split_l[0] == "Leave"){
            answer.push_back(id_to_nickname[split_l[1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}
