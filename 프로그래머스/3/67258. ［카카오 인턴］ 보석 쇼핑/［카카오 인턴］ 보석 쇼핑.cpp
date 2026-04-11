#include <bits/stdc++.h>

using namespace std;

// D E S S R E R R S E D

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gem_kinds(gems.begin(), gems.end());
    map<string, int> gem_cnt;
    
    int need = gem_kinds.size(), have = 0, start = 0;
    int ans_s = 0, ans_e = gems.size() - 1;
    
    for (int end = 0; end < gems.size(); end++) {
        gem_cnt[gems[end]]++;
        if (gem_cnt[gems[end]] == 1)
            have++;
        
        while (have == need) {
            if (end - start < ans_e - ans_s) {
                ans_s = start;
                ans_e = end;
            }
            
            gem_cnt[gems[start]]--;
            if (gem_cnt[gems[start]] == 0)
                have--;
            start++;
        }
    }
    
    answer.push_back(ans_s + 1);
    answer.push_back(ans_e + 1);
    
    return answer;
}