#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    if(count(a.begin(),a.end(),a[0]) == n) {
        cout <<"yes"<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 1) {
            a[i] += a[i] % 10;
        }
    }
    if(count(a.begin(),a.end(),a[0]) == n) {
        cout <<"yes"<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i]%10 == 0) {
            cout<< "no\n";
            return;
        }
    }
    for(int i = 0; i < n; i++){
        while(a[i]%10 != 2) {
            a[i] += a[i] % 10;
        }
        a[i] = a[i] % 20;
    }
    if(count(a.begin(),a.end(),a[0]) == n) {
        cout <<"yes"<<endl;
        return;
    }
    cout << "no\n";
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