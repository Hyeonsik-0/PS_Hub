#include <bits/stdc++.h>

using namespace std;

// 앞의 상자 크기 < 뒤의 상자 크기 -> 뒷 상자에 앞 상자를 넣을 수 있음.
// DP 문제라고 생각함. why? DP[i] = i 상자가 마지막 상자일 때, 한 번에 넣을 수 있는 최대의 상자 개수
// DP[i] = i 상자보다 작은 앞쪽의 j 상자 중 최대가 되는 DP[j] 또는 0) + 1

int main(void) {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    vector<int> DP(N, 0);
    DP[0] = 1;

    for (int i = 1; i < N; i++) {
        int t = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] and t < DP[j])
                t = DP[j];
        }
        DP[i] = t + 1;
    }

    cout << *max_element(DP.begin(), DP.end());
}