#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int l = 0, r = 0;
    int sum = 0;
    int d = 0;
    while(r < n){
        sum+=a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        d = max(d, r - l + 1);
        r++;
    }
    cout << d;
    return 0;
}
