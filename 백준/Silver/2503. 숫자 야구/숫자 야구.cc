#include <bits/stdc++.h>

using namespace std;

// 서로 다른 세 자리 숫자 -> 9*9*8 가지 경우의 수 (어림짐작으로 100~999)
// 주어지는 입력으로부터 만족하는 후보만 남겨두는 방법 사용 -> 틀림
// 문제에 '1에서 9까지의 서로 다른 숫자 세 개로 구성된 세 자리 수'라고 명시됨. -> 0은 제외

int main(void) {
    int N;
    vector<bool> answers(1000, false);
    for (int i = 100; i < 1000; i++) {
        int t1, t2, t3;
        t1 = i/100;
        t2 = (i/10)%10;
        t3 = i%10;

        if (t1 == t2 or t2 == t3 or t3 == t1)
            continue;
        if (t1 == 0 or t2 == 0 or t3 == 0)
            continue;
        answers[i] = true;
    }
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num, s, b;
        cin >> num >> s >> b;

        for (int i = 100; i < 1000; i++) {
            if (!answers[i])
                continue;
            int cs, cb;
            cs = cb = 0;

            int t1, t2, t3;
            int n1, n2, n3;
            t1 = i/100;
            t2 = (i/10)%10;
            t3 = i%10;
            n1 = num/100;
            n2 = (num/10)%10;
            n3 = num%10;

            if (t1 == n1)
                cs++;
            else if (t1 == n2 or t1 == n3)
                cb++;
            if (t2 == n2)
                cs++;
            else if (t2 == n1 or t2 == n3)
                cb++;
            if (t3 == n3)
                cs++;
            else if (t3 == n1 or t3 == n2)
                cb++;
            
            if (s == cs and b == cb){
                continue;
            }
            answers[i] = false;
        }
    }

    cout << count(answers.begin(), answers.end(), true);
}