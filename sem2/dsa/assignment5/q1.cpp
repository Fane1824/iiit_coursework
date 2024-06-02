#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<bool> &visited, vector<vector<int> > &adjlist, int x) {
    visited[x] = true;
    for (auto i: adjlist[x]) {
        if (!visited[i]) {
            DFS(visited, adjlist, i);
        }
    }
}

int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<int> >adjlist(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    vector<bool>visited(n, false);
    vector<int>output;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(visited, adjlist, i);
            output.push_back(i);
        }
    }
    if (output.size() <= 1) {
        cout << "0" << "\n";
    } else {
        cout << output.size()-1 << "\n";
        for (int i = 1; i < output.size(); i++) {
            cout << output[0]+1 << " ";
            cout << output[i]+1 << "\n";
        }
            
    }
    return 0;
}