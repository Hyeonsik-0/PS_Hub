#include<bits/stdc++.h>
using namespace std;

// 전형적인 미로찾기 문제
// (0, 0) -> (n, m) 최소 거리 이동으로 도착: BFS 사용가능

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<int> q;
    
    // init start position
    q.push(0);
    visited[0][0] = 1;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while (!q.empty()) {
        int pos = q.front(); q.pop();
        int x = pos / m, y = pos % m;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
        
            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                if (!visited[nx][ny] and maps[nx][ny] == 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(nx * m + ny);
                }
            }
        }
    }
    answer = visited[n - 1][m - 1] != 0 ? visited[n - 1][m - 1] : -1;
    
    return answer;
}