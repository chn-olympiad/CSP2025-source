#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, flag=0, pat=0;
    long long ans;
    cin>>n>>m;
    string cd;
    vector<int> p(n);
    cin>>cd;
    for(int i=0; i<n; i++){
        cin>>p[i];
        if(cd[i]=='0') flag++;
    }
    if(!flag){
        while(n>=1){
            ans*=n;
            n--;
        } cout<<ans;
        return 0;
    }
}