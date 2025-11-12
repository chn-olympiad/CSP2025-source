#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
long long n,m,a[505],dp[505],nd[505];
char s[505];
bool t[505];
long long sl(int p,int g,int c){
    if(p<1) return 1;
    if(g<0) return 0;
    int ct=c;
    while(a[ct]>nd[p]) ct--;
    long long t1=(p-ct)*sl(p-1,g,min(p-1,ct));
    long long t2=0;
    if(g) t2=p*sl(p-1,g-1,min(p-1,ct));
    return (t1+t2)%md;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        t[i]=(s[i-1]=='0')?1:0;
        nd[i]=t[i]+nd[i-1];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    if(nd[n]>m){
        cout<<0<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<sl(n,n-m,n)<<endl;
    return 0;
}