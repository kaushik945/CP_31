#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int check(vector<vector<int>>& precomp, int l, int r){
    int ans = 0;
    for(int i = 0; i <= 30 ; i++){
        if (!(precomp[i][r+1] - precomp[i][l]))
            ans += 1 << i;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> precomp(32,vector<int> (n+1,0));

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i <= 30 ; i++){
        for(int j = 0; j < n; j++){
            precomp[i][j+1] = precomp[i][j]; 
            if(((1 << i) & a[j] )== 0) // if bit 
                precomp[i][j+1]++;
        }
    }

    int q;
    cin >> q;

    while (q--){
        int l,k;
        cin >> l >> k;
        l--;
        int low = l, high = n-1;
        if(a[l] < k){
            cout << -1 << " ";
            continue;
        }
        while (low < high){
            int mid = (low+high+1)/2; // for greatest poss val of r.
            if (check(precomp,l,mid) >= k)
                low = mid;
            else
                high = mid - 1;
        }
        cout << low+1 << " ";
    }
    cout << "\n";
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