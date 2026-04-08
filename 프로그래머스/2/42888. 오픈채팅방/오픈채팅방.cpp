#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_names;
    vector<string> commands;
    vector<string> uids;
    
    for (string info : record) {
        string command = info.substr(0, info.find(" "));
        info = info.substr(info.find(" ") + 1);
        string uid = info.substr(0, info.find(" "));
        string user_name = info.substr(info.find(" ") + 1);
        
        if (command == "Change") {
            user_names[uid] = user_name;
        }
        else {
            if (command == "Enter")
                user_names[uid] = user_name;
            commands.push_back(command);
            uids.push_back(uid);
        }
    }
    
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "Enter")
            answer.push_back(user_names[uids[i]] + "님이 들어왔습니다.");
        else if (commands[i] == "Leave")
            answer.push_back(user_names[uids[i]] + "님이 나갔습니다.");
    }
    
    return answer;
}