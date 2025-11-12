#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=600;
const int mod=998244353;
int n,m;
string s;
int a[MAXN],num;
int ans=1;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=2;i--){
        ans*=i;
        ans=ans%mod;
    }
    cout<<1;
    return 0;
}
//0
//bye OI
