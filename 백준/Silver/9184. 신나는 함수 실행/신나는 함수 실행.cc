#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// 문제에서 제시하는 재귀함수의 동작과 동일하게 코드 짜기.
// 기존의 재귀함수의 동작이 느리다! -> 어떻게 최적화 할까?
// 아래는 주어진 재귀 함수
/*
    if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
        1
    
    if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
        w(20, 20, 20)

    if a < b and b < c, then w(a, b, c) returns:
        w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

    otherwise it returns:
        w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/
// a, b, c 중 하나라도 0 이하라면 1 반환
// a, b, c 중 하나라도 20 초과하면 w(20, 20, 20)을 반환 -> w(20, 20, 20)을 호출하는 경우가 만을 것 같은데.. 이거 값 미리 알면 되지 않나?
// a < b < c 순이면, w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c) 반환
// 그 외:  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) 반환

// 재귀 함수를 간단화 하는 작업은 어려워 보임.. A[20][20][20] 3차원 배열에 정답 미리 써놓기?

int A[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 or b <= 0 or c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    
    if (A[a][b][c] != INF) {
        return A[a][b][c];
    }
    
    if (a < b and b < c) {
        A[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        A[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    
    return A[a][b][c];
}

int main(void) {
    for (int i = 0 ; i <= 20; i++)
        for (int j = 0; j <= 20; j++)
            for (int k = 0; k <= 20; k++) {
                if (i == 0 or j == 0 or k == 0)
                    A[i][j][k] = 1;
                else
                    A[i][j][k] = INF;
            }
    int a, b, c;
    while(cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}