#include <bits/stdc++.h>
using namespace std;
bool nt(int n){
    if(n<2) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i<=sqrt(n); i+=6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int tcs(int n){
    int tong = 0;
    while(n>0){
        tong+=n%10;
        n/=10;
    }
    return tong;
}
int main() {

    int n;
    cin >> n;
    if(nt(n)){
        cout << "PRIME";
    }
    else{
        cout << tcs(n);
    }

    return 0;
}
