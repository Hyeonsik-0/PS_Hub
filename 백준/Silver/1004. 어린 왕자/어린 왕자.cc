#include <bits/stdc++.h>

using namespace std;


// 출발지, 도착지 구분은 의미 x
// 각 점이 속하는 행성계 구하기
// 겹치는 행성계 및 소속되지 않는 행성계 제거
// 나머지 행성계 카운트해서 더하기

// 문제 풀이는 좋았음.
// 실수가 많았다. -> x1, y1 순이 아니라 x1, x2 순으로 입력을 받음..


struct P {
    int cx, cy, r;
};

bool is_include(int x1, int y1, int x2, int y2, int r) {
    if (pow(x2 - x1, 2) + pow(y2 - y1, 2) <= pow(r, 2))
        return true;
    return false;
}

int main(void) {
    int T;
    cin >> T;

    while (T--) {
        int N, x1, y1, x2, y2;
        vector<P> Planets;
        cin >> x1 >> y1 >> x2 >> y2 >> N;

        for (int i = 0; i < N; i++) {
            P tp;
            cin >> tp.cx >> tp.cy >> tp.r;
            Planets.push_back(tp);
        }

        int start, end;
        start = end = 0;

        for (int i = 0; i < N; i++) {
            bool s = is_include(x1, y1, Planets[i].cx, Planets[i].cy, Planets[i].r);
            bool e = is_include(x2, y2, Planets[i].cx, Planets[i].cy, Planets[i].r);

            if (s and !e)
                start++;
            else if (!s and e)
                end++;
        }

        cout << start + end << endl;
    }
}