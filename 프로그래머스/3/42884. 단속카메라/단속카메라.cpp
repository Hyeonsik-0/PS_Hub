#include <bits/stdc++.h>

using namespace std;

// 모든 차량이 한 번은 카메라를 만나도록 설치
// 차량이 지나는 마지막 구간에 설치하면 되지 않을까?

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](auto a, auto b){return a[1] < b[1];});
    set<int> cams;
    
    for (auto route : routes) {
        bool add = true;
        for (int cam : cams) {
            if (route[0] <= cam and cam <= route[1]) {
                add = false;
                break;
            }
        }
        if (add) {
            cams.insert(route[1]);
            answer++;
        }
    }
    
    return answer;
}