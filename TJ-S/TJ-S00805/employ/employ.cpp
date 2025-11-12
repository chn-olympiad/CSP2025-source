#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
typedef long long ll;
ll n,m,a[N],t,ans=1;
string str;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    t=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) t--;
    }
    for(int i=t;i>=1;i--){
        ans*=i;
        ans%=mod;
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
