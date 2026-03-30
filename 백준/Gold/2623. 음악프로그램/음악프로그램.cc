#include <bits/stdc++.h>

using namespace std;

// 순서를 정하는 문제: 위상 정렬을 이용할 수 있음
// 위상 정렬은 보통 DAG에서 이용 가능함. 이 문제에서는 DAG인지 아닌지 판별이 필요
// 즉, 방향 그래프 내에 사이클의 존재를 isCyclic함수로 판별 가능
// 그 이후에는 위상 정렬을 통해 가능한 순서 하나 출력

// DFS를 이용해서 노드를 재귀적으로 방문함 -> 마지막 노드에서 뒤로 갈 수 있는지 확인 (백트래킹)
bool isCyclicUtil(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& recSt) {
    if (recSt[u]) return true;
    if (vis[u]) return false;

    vis[u] = true;
    recSt[u] = true;

    for (int v : adj[u]) {
        if (isCyclicUtil(adj, v, vis, recSt))
            return true;
    }

    recSt[u] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> vis(V, false);
    vector<bool> recSt(V, false);

    for (int i = 1; i < V; i++) {
        if (!vis[i] && isCyclicUtil(adj, i, vis, recSt))
            return true;
    }
    return false;
}

void Topo(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            Topo(it, vis, adj, st);
        }
    }
    st.push(node);
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int num_of_singer;
        cin >> num_of_singer;
        vector<int> order(num_of_singer);
        for (int j = 0; j < num_of_singer; j++) {
            cin >> order[j];
        }
        for (int j = 0; j < num_of_singer - 1; j++) {
            for (int k = j + 1; k < num_of_singer; k++) {
                adj[order[j]].push_back(order[k]);
            }
        }
    }

    if (isCyclic(adj)) {
        cout << 0;
        return 0;
    }

    stack<int> st;
    vector<int> vis(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            Topo(i, vis, adj, st);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    for (auto it : ans) {
        cout << it << endl;
    }

    /*
        for (int i = 1; i <= N; i++) {
            cout << i << ": ";
            for (int x : adj[i])
                cout << x << " ";
            cout << '\n';
        }
    */
}