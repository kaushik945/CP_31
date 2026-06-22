#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    string brackets;
    cin >> brackets;
    vector<int> bal(n+1,0);
    bal[0] = (brackets[0] == '(' ? 1 : -1);
    for(int i = 1; i < n; i++){
        if(brackets[i] == ')') bal[i] = bal[i-1] - 1;
        else bal[i] = bal[i-1] + 1;
    }
    if(bal[n-1] != 0){
        cout << -1 << "\n";
        return;
    }
    if(*min_element(bal.begin(),bal.end()) == 0){
        cout << 1 << "\n";
        for(int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
        return;
    }
    if(*max_element(bal.begin(),bal.end()) == 0){
        cout << 1 << "\n";
        for(int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
        return;
    }
    cout << 2 << "\n";
    for(int i = 0; i < n; i++){
        if(bal[i] > 0){
            cout << 1 << " ";
        }else if(bal[i] < 0){
            cout << 2 << " ";
        }else{
            if(bal[i-1] >0) cout << 1 << " ";
            else cout << 2 << " ";
        }
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