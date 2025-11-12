#include <bits/stdc++.h>
using namespace std;
long long n,m,mod=998244353,d[510];
string s;
long long c[510],ss[510],cnt,dp[(long long)(1<<18)+10][20],ans;
bool flag1=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        d[i]=i;
    }
    do{
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0' || sum>=c[d[i]]){
                sum++;
            }
            //cout<<c[i]<<' ';//c
        }
        //cout<<sum<<'\n';//c
        if(n-sum>=m){
            ans++;
        }
    }while(next_permutation(d+1,d+1+n));
    cout<<ans<<'\n';
    return 0;
}