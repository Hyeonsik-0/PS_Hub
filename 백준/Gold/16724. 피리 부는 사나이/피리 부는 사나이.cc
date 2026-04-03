#include <bits/stdc++.h>

using namespace std;

// 난이도: 골드3 / 제한 시간: 57min / 해결 시간: 
// 알고리즘 분류: BFS
// 목적: 2차원 그래프에 세이프 존 최소한 추가하기
// 규칙: 그래프 어디에 위치해 있더라도 세이프 존으로 들어가야 함

// 어디에 위치해 있더라도 세이프존에 들어가야 하기 때문에 그래프 구역이 나뉨
// 따라서 BFS를 이용해서 나뉜 구역의 수 구하기
// 해결할 문제: 세이프 존을 어디 세워야 하는가?

// 사이클이 발생했을 때, 처리하는 과정이 매끄럽지 않아서 오래 걸림.
// 상태를 3개로 나누고, 방문 경로를 저장했다가 업데이트하는 방법으로 해결

int N, M;

void next_pos(char a, int& x, int& y) {
    if(a == 'U') {
        x--;
    }
    else if(a == 'D') {
        x++;
    }
    else if(a == 'L') {
        y--;
    }
    else if(a == 'R') {
        y++;
    }
}

void f(int sx, int sy, int& ans, vector<vector<char>>& adj, vector<vector<int>>& state) {
    vector<pair<int, int>> path;
    int x = sx, y = sy;
    
    while (state[x][y] == 0) {
        state[x][y] = 1;
        path.push_back({x, y});
        next_pos(adj[x][y], x, y);
    }
    
    if (state[x][y] == 1) ans++;

    for (auto &p : path) {
        state[p.first][p.second] = 2;
    }
}


int main() {
    cin >> N >> M;
    vector<vector<char>> adj(N, vector<char>(M));
    // 0: 미방문, 1: 현재 경로(탐색 중), 2: 탐색 완료
    vector<vector<int>> state(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }

    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (state[i][j]) continue;
            f(i, j, ans, adj, state);
        }
    }

    cout << ans;

    return 0;
}
