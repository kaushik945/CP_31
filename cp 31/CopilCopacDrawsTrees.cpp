#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dp;
vector<vector<int>> adj;
map<pair<int,int>,int> idx;

void dfs(int child, int parent){
    for(auto v : adj[child]){
        if(v == parent) continue;
        if(idx[{child,v}] > idx[{parent,child}]){
            dp[v] = dp[child]; 
        }else{
            dp[v] = dp[child] + 1;
        }
        dfs(v,child);
    }
}
void solve()
{
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
	dp.assign(n, 0);
	idx.clear();
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        idx[{u,v}] = i;
        idx[{v,u}] = i;
    }
    idx[{-1,0}] = -1;
    dp[0] = 1;
    dfs(0,-1);
    cout << *max_element(dp.begin(),dp.end()) << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}