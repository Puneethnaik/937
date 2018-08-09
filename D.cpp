#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
vector<vector<int> > used, par, g;
vector<int> visi, out;
bool cycle = false;
int ans;
void dfs(int u, int cur){
    used[u][cur] = 1;
    // cout << u << ", " << cur << endl;
    if(cur == 0 and out[u] == 0){
        ans = u;
    }
    for(int v : g[u]){
        if(!used[v][cur ^ 1]){
            // cout << u << ", " << cur << " <- " << v << " " << (cur ^ 1) << endl;
            par[v][cur ^ 1] = u;
            dfs(v, cur ^ 1);
        }
    }
}

void dfs2(int u){
    visi[u] = 1;
    for(int it : g[u]){
        if(!visi[it]){
            dfs2(it);
        }
        else if(visi[it] == 1){
            cycle = true;
        }
    }
    visi[u] = 2;
}
int main(){
    int n, m;
    cin >> n >> m;
    //push (1, 0) and (1, 1) states
    out.resize(n + 1, 0);
    visi.resize(n + 1, 0);
    used.resize(n + 1, vector<int> (2));
    par.resize(n + 1, vector<int> (2));
    g.resize(n + 1);
    for(int i = 1 ; i <= n ; i++){
        int c;
        int v;    
        cin >> c;
        out[i] = c;
        for(int j = 0 ; j < c; j++){
            cin >> v;
            g[i].push_back(v);
        }
    }
    int s;
    cin >> s;
    dfs(s, 1);
    if(ans){
        cout << "Win\n";
        stack<int> path;
        int t = ans, cur = 0;
        // cout << "retracing path\n";
        while(par[t][cur] != 0){
            path.push(t);
            // cout << t << ", " << cur << " <- ";
            t = par[t][cur];
            cur = cur ^ 1;  
            // cout << t << ", " << cur << " <- ";
            
        }
        path.push(s);
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
    }
    else{
        dfs2(s);
        if(cycle){
            cout << "Draw\n";
        }
        else{
            cout << "Lose\n";
        }
    }
    return 0;
}