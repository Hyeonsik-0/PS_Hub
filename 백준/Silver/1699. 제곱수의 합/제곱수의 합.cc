#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

// 제곱수의 합으로 주어진 N 만들기. 단, 항의 개수가 최소가 되도록 하기
// 단순하게 생각해서 숫자 N이 주어지면, N보다 작은 최대의 제곱수 X 찾고, 그 수를 빼기 -> N - X보다 작은 최대 제곱수 찾기 -> 반복
// 위 방식은 오류: N = 18일 때, 정답은 3^2 + 3^2 이지만, 4^2 + 1 + 1을 반환
// 그리디하게 못 풂 -> DP?

int main(void) {
    int N, cnt = 0;
    cin >> N;
    // cout << "Mininum square number of N is " << find_min_square_num(N) << endl;

    vector<int> DP(100001, 1e9);
    for (int i = 1; i*i <= 100000; i++) {
        DP[i*i] = 1;
    }

    for (int i = 1; i <= 100000; i++) {
        if (DP[i] != 1e9)
            continue;
        for (int j = 1; j*j <= i; j++) {
            DP[i] = min(DP[i], DP[i - j*j] + 1);
        }
    }

    cout << DP[N];
}