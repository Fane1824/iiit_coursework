#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<vector<int>>> &adjlist, int n) {
    vector<long long int> dist(n, LLONG_MAX);                            
    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> fiberarr(n, 0);
    dist[0] = 0;
    parent[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p;
    p.push(make_pair(0, 0));
    int ct = 0;
    while (!p.empty()){
        int curr = p.top().second;
        p.pop();
        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        for (auto x : adjlist[curr]){
            int nod = x[0];
            int wt = x[1];
            int fiber = x[2];
            if (!visited[nod]){
                if (dist[nod] > dist[curr] + wt) {
                    dist[nod] = dist[curr] + wt;
                    parent[nod] = curr;
                    p.push(make_pair(dist[nod], nod));
                    if (fiber) {
                        fiberarr[nod] = 1;
                    }
                }
                else if (dist[nod] == dist[curr] + wt && fiberarr[nod] && fiber == 0) {
                    parent[nod] = curr;
                    fiberarr[nod] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (parent[i] == 0 && fiberarr[i]) {
            ct += 1;
        }
    }
    return ct;
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnter = 0;

    vector<vector<vector<int>>> adjlist(n);
    vector<int> protlist(n, 0);
    vector <bool> connected(n, false);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (a == b) {
            continue;
        }
        adjlist[a].push_back({b, c, 0});
        adjlist[b].push_back({a, c, 0});
    }
    int fyz = k;
    for (signed i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        if (a == 0) {
            cnter++;
            fyz--;  
            continue;
        }
        adjlist[0].push_back({a, b, 1});
        adjlist[a].push_back({0, b, 1});  
        
    }
    // cout << cnter << "\n";
    // for (int i = 0; i < adjlist.size(); i++) {
    //     cout << i + 1<< "\n";
    //     for (int j = 0; j < adjlist[i].size(); j++) {
    //         cout << adjlist[i][j][0] + 1 << " " << adjlist[i][j][1] << "\n";
    //     }
    //     cout << "\n";
    // }
    // cout << cnter << "\n";
    cnter = cnter + (fyz-dijkstra(adjlist, n));
    cout << cnter << "\n";
    
    return 0;
}

