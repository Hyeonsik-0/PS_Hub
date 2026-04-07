/*
    문제: 개인정보 수집 유효기간
    출처: https://school.programmers.co.kr/learn/courses/30/lessons/150370
    풀이 날짜: 2026-04-07
    난이도: 1
    풀이 소요 시간: 25분
    유형: 구현, 문자열
    문제 설명: 
        today는 오늘 날짜, terms는 약관 종류와 유효기간(개월), privacies는 수집일자와 약관 종류 정보이다.
        수집일자에 유효기간을 더했을 때 today보다 같거나 이전이면 파기 대상이다.
        파기해야 할 개인정보의 번호를 오름차순으로 반환한다.
    어려운 점: 
        정수형이 아닌 문자열로 계산하는 것이 익숙하지 않았다.
        날짜 계산이 까다로웠다. '년-월-일'을 '일'로 바꿔서 계산하는 방법을 사용했다.
    실수한 점:
        날짜 비교 과정에서 대소 비교 연산자를 잘못 사용했다. '<' 대신 '<='를 사용해야 했다.
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

// 날짜를 '일'로 변환하는 함수
// 논리적 오류 존재: 5월 1일은 (4*28 + 1)로 계산되어야 하지만 (5*28 + 1)로 계산됨.
int dateToDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return year * 12 * 28 + month * 28 + day;
}

bool is_destroy(int today_days, int date_days, int term) {
    return date_days + term * 28 <= today_days;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> terms_map;
    
    for (auto term_info : terms) {
        terms_map[term_info.substr(0, 1)] = stoi(term_info.substr(1));
    }

    int today_days = dateToDays(today);
    
    for (int i = 0; i < privacies.size(); i++) {
        string privacy_info = privacies[i];
        int date_days = dateToDays(privacy_info.substr(0, 10));
        string term_type = privacy_info.substr(11);

        if (is_destroy(today_days, date_days, terms_map[term_type]))
            answer.push_back(i + 1);
    }
    
    return answer;
}