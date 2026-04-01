#include <bits/stdc++.h>

using namespace std;

// DP[i][j] = i ~ j 번째 행렬까지 곱셈 연산의 최소 횟수
// DP[x][x + 1] 부터 계산해서 점점 범위를 늘려야 함. -> DP[x][x + 2] ...
// DP[0][N]을 마지막에 계산 후 출력하는게 목적
// DP[x][x]인 경우 0으로 처리

// DP[x][x + 3]인 경우, 범위 내 4 개의 행렬 A, B, C, D가 존재.
// A|BCD or AB|CD or ABC|D 중 최소값을 구해야 함.
// A|BCD: A x (B의 row & D의 col) + DP[x][x] + DP[x + 1][x + 3]
// AB|CD: (A row & B col) x (C row & D col) + DP[x][x + 1] + DP[x + 2][x + 3]
// ABC|D: (A row & C col) x D + DP[x][x + 2] + DP[x + 3][x + 3]
// DP[x][x + 3] = min(위의 세 가지 경우)

int main() {
    int N;
    vector<vector<int>> DP(501, vector<int>(501, INT_MAX));
    vector<pair<int, int>> matrix(501);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        matrix[i] = {a, b};
    }

    // DP[i][i]는 0으로 초기화
    for (int i = 1; i <= N; i++) {
        DP[i][i] = 0;
    }
    // i부터 i + 1 번째 행렬까지의 곱셈 연산 수 (고정 값)
    for (int i = 1; i <= N - 1; i++) {
        DP[i][i + 1] = matrix[i].first * matrix[i].second * matrix[i + 1].second;
    }
    
    for (int i = 2; i < N; i++) { // 범위 맞는지 확인
        for (int j = 1; j + i <= N; j++) {
            for (int k = 0; k < i; k++) {
                DP[j][j + i] = min(DP[j][j + i], matrix[j].first * matrix[j + k].second * matrix[j + i].second + DP[j][j + k] + DP[j + k + 1][j + i]);
            }
        }
    }

    cout << DP[1][N];

    return 0;
}
