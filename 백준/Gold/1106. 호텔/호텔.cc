#include <bits/stdc++.h>

using namespace std;

// 최대한 효율적으로 투자하는 문제 -> DP로 풀기
// 주어진 C 이상의 고객을 유치하기
// DP[i] = i 명의 고객을 유치하기 위한 최소 비용

int main(void) {
    int C, N;
    cin >> C >> N;
    vector<pair<int, int>> informations(N);
    vector<int> DP(1001, 1e9);
    for (int i = 0; i < N; i++) {
        int cost, customer;
        cin >> cost >> customer;
        informations[i] = {cost, customer};
    }

    for (int i = 1; i <= C; i++) {
        for (auto information : informations) {
            int cost = information.first, customer = information.second;
            if (i - customer <= 0)
                DP[i] = min(DP[i], cost);
            else
                DP[i] = min(DP[i], DP[i - customer] + cost);
        }
    }

    cout << DP[C];
    /* 
        for (int i = 1; i <= 100; i++)
        cout << i << ": " << DP[i] << endl;
    */
}