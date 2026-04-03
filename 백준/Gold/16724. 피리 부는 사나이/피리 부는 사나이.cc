#include <bits/stdc++.h>

using namespace std;

// 난이도: 골드3 / 제한 시간: 57min / 해결 시간: 
// 알고리즘 분류: DFS
// 목적: 2차원 그래프에 세이프 존 최소한 추가하기
// 규칙: 그래프 어디에 위치해 있더라도 세이프 존으로 들어가야 함

// 어디에 위치해 있더라도 세이프존에 들어가야 하기 때문에 그래프 구역이 나뉨
// 따라서 DFS 이용해서 나뉜 구역의 수 구하기
// 해결할 문제: 세이프 존을 어디 세워야 하는가?

int N, M;

void find_next(char a, int& x, int& y) {
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

void dfs(int x, int y, int& k, vector<vector<char>>& adj, vector<vector<int>>& vis) {
    stack<pair<int, int>> St;
    St.push({x, y});
    vis[x][y] = k;

    while (!St.empty()) {
        int cur_x, cur_y, nxt_x, nxt_y;
        tie(cur_x, cur_y) = St.top();
        St.pop();
        nxt_x = cur_x;
        nxt_y = cur_y;
        find_next(adj[cur_x][cur_y], nxt_x, nxt_y);

        if(!vis[nxt_x][nxt_y]) {
            St.push({nxt_x, nxt_y});
            vis[nxt_x][nxt_y] = k;
        }
        else if (vis[nxt_x][nxt_y] != k){
            int c = vis[nxt_x][nxt_y];
            int nx, ny;
            nx = x;
            ny = y;
            while (vis[nx][ny] != c) {
                vis[nx][ny] = c;
                find_next(adj[nx][ny], nx, ny);
            }
            break;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<char>> adj(N, vector<char>(M));
    vector<vector<int>> vis(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }

    
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j])
                dfs(i, j, ++k, adj, vis);
        }
    }
    
    set<int> cnts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnts.insert(vis[i][j]);
        }
    }
    cout << cnts.size();
    return 0;
}
