#include <bits/stdc++.h>

using namespace std;

// 실버 1 DP / 제한 시간: 35min
// 왜 DP인가?: 1..n 잔의 포도주를 최대한 많이 마시기 위한 최적화 문제
// 규칙: 포도주 원샷 & 빈 잔 원위치 & 연속으로 놓여진 3잔은 마시기 불가능
// 목적: 포도주를 최대한 많은 양 마시기

// DP의 차원? i 앞의 잔을 연속으로 0 또는 1 잔 마셨을 때, 무조건 마셔야 함. or i 잔을 마시지 않기
// DP[i][j][k]: 0..i 잔의 최대량 j(i를 마시면 1, 아니면 0), k(i - 1을 마시면 1, 아니면 0)
// ? 0 0 | DP[i][0][0] = max(DP[i - 1][0][0], DP[i - 1][0][1])
// ? 1 0 | DP[i][0][1] = max(DP[i - 1][1][0], DP[i - 1][1][1])
// ? 0 1 | DP[i][1][0] = max(DP[i - 1][0][0], DP[i - 1][0][1]) + adj[i]
// 0 1 1 | DP[i][1][1] = DP[i - 1][1][0] + adj[i]

// 다른 풀이: DP[i] = max(DP[i - 1], DP[i - 2] + adj[i], DP[i - 3] + adj[i - 1] + adj[i])
// 위 식에서 DP[i]: i 잔까지 마실 때 최대량
// DP[i - 1]: i - 1 잔까지 마실 때 최대량 (i 잔을 마시지 않음)
// DP[i - 2] + adj[i]: i - 2 잔까지 마실 때 최대량 + i 잔의 양 (i - 1 잔을 마시지 않음)
// DP[i - 3] + adj[i - 1] + adj[i]: i - 3 잔까지 마실 때 최대량 + i - 1 잔의 양 + i 잔의 양 (i - 2 잔을 마시지 않음)

int main() {
    int n;
    cin >> n;
    vector<int> adj(n);
    int DP[n][2][2];
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }
    
    // 기저 값 초기화
    DP[0][0][0] = 0;
    DP[0][0][1] = 0;
    DP[0][1][0] = adj[0];
    DP[0][1][1] = adj[0];
    
    for (int i = 1; i < n; i++) {
        DP[i][0][0] = max(DP[i - 1][0][0], DP[i - 1][0][1]);
        DP[i][0][1] = max(DP[i - 1][1][0], DP[i - 1][1][1]);
        DP[i][1][0] = max(DP[i - 1][0][0], DP[i - 1][0][1]) + adj[i];
        DP[i][1][1] = DP[i - 1][1][0] + adj[i];
    }
    
    int ans = 0;
    for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 1; k++) {
            ans = max(ans, DP[n - 1][j][k]);
        }
    }
    cout << ans;

    return 0;
}
