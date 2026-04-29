#include <bits/stdc++.h>

using namespace std;

// 50 min
// 숙련도를 선형적으로 증가시킬 필요는 없음
// 기준? 숙련도는 양의 정수니까 1로 기준 잡고 풀리면 현재 숙련도 k x2, 안 풀리면 이전 숙련도 k/2와 현재 숙련도 k의 중간 (k/2 + k)/2으로 이동
// 위 방법보다 diffs의 최대값을 최대 숙련도, 1을 최소 숙련도로 잡고 이분 탐색하는게 좋아보임

bool is_possible(int level, vector<int>& diffs, vector<int>& times, long long limit) {
    int time_prev = 0, time_cur = 0;
    long long time_total = 0;
    
    for (int i = 0; i < diffs.size(); i++) {
        time_prev = time_cur;
        time_cur = times[i];
        
        if (level < diffs[i]) {
            time_total += (time_prev + time_cur) * (diffs[i] - level) + time_cur;
        }
        else {
            time_total += time_cur;
        }
    }
    
    if (time_total <= limit)
        return true;
    return false;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int s = 1, e = *max_element(diffs.begin(), diffs.end());
    
    while (s < e) {
        if (is_possible((s + e)/2, diffs, times, limit)) {
            e = (s + e)/2;
        }
        else {
            s = (s + e)/2 + 1;
        }
    }
    
    answer = e;
    
    return answer;
}