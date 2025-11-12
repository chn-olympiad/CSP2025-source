#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,m;
int s[N];
int c[N];
int psNum;
int fr,ct[N];
int p;
int f=1;
void solve(int w){
    if(w>=n&&psNum>=m){
        p++,p%=mod;
        return;
    }
    for(int i=0;i<n;i++)
        if(!ct[i]){
            ct[i]=1;
            if(!s[w]||c[i]<=fr){
                fr++;
                solve(w+1);
                fr--;
            }else
                psNum++,solve(w+1),psNum--;
            ct[i]=0;
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        s[i]=a-'0';
        if(!s[i])
            f=0;
    }
    if(f){
        unsigned long long ans=1;
        for(unsigned long long i=2;i<=n;i++){
            ans*=i;
            if(ans>=mod)
                ans%=mod;
        }
        cout<<(int)ans<<'\n';
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    solve(0);
    cout<<p<<'\n';
    return 0;
}
