#include <bits/stdc++.h>

using namespace std;

// 주어진 직사각형 내부의 정사각형 만들기
// 정사각형 한 변의 최대 길이 = 50, 1부터 세기? 시간적으로 괜찮아보임

bool is_available_square(int start_x, int start_y, int side_length, vector<vector<int>> &A, int A_row_size, int A_col_size) {
    side_length--; // 실제 변의 길이 반영
    if (start_x + side_length >= A_row_size or start_y + side_length >= A_col_size)
        return false;
    
    int number1 = A[start_x][start_y];
    int number2 = A[start_x + side_length][start_y];
    int number3 = A[start_x][start_y + side_length];
    int number4 = A[start_x + side_length][start_y + side_length];

    if (number1 == number2 and number1 == number3 and number1 == number4)
        return true;
    return false;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    
    int max_side_length = min(N, M);
    int res = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 2; k <= max_side_length; k++) {
                if (k <= res)
                    continue;
                if(is_available_square(i, j, k, A, N, M)) {
                    res = k;
                    // cout << "start_x: " << i << ", start_y: " << j << ", side_length: " << k << "\n";
                }
            }
        }
    }
    cout << pow(res, 2);
}