#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> musics;
    map<string, int> total_plays;
    vector<pair<int, string>> genre_rank;
    
    for (int i = 0; i < genres.size(); i++) {
        musics[genres[i]].push_back({plays[i], i});
        total_plays[genres[i]] += plays[i];
    }
    
    for (auto [key, value] : total_plays) {
        genre_rank.push_back({value, key});
    }
    sort(genre_rank.begin(), genre_rank.end(), [](auto a, auto b){return a.first > b.first;});
    
    for (auto [_, genre] : genre_rank) {
        sort(musics[genre].begin(), musics[genre].end(), [](auto a, auto b){return a.first > b.first;});
        
        answer.push_back(musics[genre][0].second);
        if (musics[genre].size() > 1)
            answer.push_back(musics[genre][1].second);
    }
    
    // 필요한 값이 뭐지? index-genre-play 연결, genre-sum of play 연결
    return answer;
}