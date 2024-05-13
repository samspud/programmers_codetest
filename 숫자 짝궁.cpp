#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

string solution(string X, string Y) {
    string answer = "";
    string jjaks = "";
    vector<int> X_numbers(10, 0);
    vector<int> Y_numbers(10, 0);
    vector<int> jjaks_numbers(10, 0);
    
    for (char& x : X){
        X_numbers[x - '0'] += 1;
    }
    
    for (char& y : Y){
        Y_numbers[y - '0'] += 1;
    }
    
    for (int i = 0; i < 10; i++){
        jjaks_numbers[i] = min(X_numbers[i], Y_numbers[i]);
    }
    
    for (int j = 0; j < jjaks_numbers.size(); j++){
        jjaks.append(jjaks_numbers[jjaks_numbers.size() - j - 1], jjaks_numbers.size() - j - 1 + '0');
        
    }
    
    answer = jjaks;
    
    if (jjaks == ""){
        answer = "-1";
    } else if (jjaks[0] == '0'){
        answer = "0";
    }
    
    return answer;
}
