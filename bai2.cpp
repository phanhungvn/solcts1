#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int ln = INT_MIN;
    int sl = 0;
    for(auto p : mp){
        if(p.second > ln)
        {
            ln = max(ln, p.second);
            sl = p.first;
        }
    }
    sort(a.begin(), a.end());
    auto it = lower_bound(a.begin(), a.end(), sl) - a.begin() + 1;
    cout << sl << "\n" << it;

    return 0;
}
