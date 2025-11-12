#include <bits/stdc++.h>
using namespace std;
int n,m,c[509];
string s;
const int mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for (int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    int s=1;
    for (int i=1;i<=n;i++){
        s=1ll*i*s%mod;
    }
    cout<<s;
    return 0;
}
