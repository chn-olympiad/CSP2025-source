#include<iostream>
#define LL long long
using namespace std;
const int mod=998244353;
const int N=510;
int n,m;
int c[N];
string s;
int cnt;
LL ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=0) cnt++;
    }
    for(int i=1;i<=cnt+1;i++){
        ans=(ans*i)%mod;
    }
    cout<<ans;
    return 0;
}