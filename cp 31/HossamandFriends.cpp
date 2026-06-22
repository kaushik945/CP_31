#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> uk(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u >> v;
        if(u > v) swap(u,v);
        uk[v] = max(uk[v],u);
    }
    ll ans  = 1;
    vector<int> dp(n+1);
    dp[1] = 1;
    ans = 1;
    for(int i = 2; i <= n ; i++){
        dp[i] = max(dp[i-1],uk[i] + 1);
        ans += i - dp[i] + 1;
    }
    cout<<ans<<endl;
    
    
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