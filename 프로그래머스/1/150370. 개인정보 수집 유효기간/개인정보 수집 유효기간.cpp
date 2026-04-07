#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_destroy(string today, string date, int term) {
    int today_time, date_time;
    // 계산 편의성을 위해 '년-월-일'을 '일'로 바꾸기
    // 오류가 있지만 계산에는 문제 없음. e.g., 5월달은 28일을 5번이 아닌 4번을 곱해야 함
    today_time = (stoi(today.substr(0, 4)) - 1) * 12 * 28 + (stoi(today.substr(5, 2)) - 1) * 28 + stoi(today.substr(8, 2));
    date_time = (stoi(date.substr(0, 4)) - 1) * 12 * 28 + (stoi(date.substr(5, 2)) - 1) * 28 + stoi(date.substr(8, 2));
    if (date_time + term * 28 > today_time)
        return false;
    return true;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> mapped_terms;
    
    for (string s : terms) {
        string term = s.substr(0, 1);
        int period = stoi(s.substr(1));
        mapped_terms[term] = period;
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        string p = privacies[i];
        string date = p.substr(0, 10);
        string term = p.substr(11);
        if (is_destroy(today, date, mapped_terms[term]))
            answer.push_back(i + 1);
    }
    
    return answer;
}