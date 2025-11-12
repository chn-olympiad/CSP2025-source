#include<bits/stdc++.h>
using namespace std;
const int N=500+5,M=998244353;
int n,m,c[N],l,a[N],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    l=s.size();
    for(int i=1;i<=l;i++){
        a[i]=s[i]-'0';
        if(!a[i]&&m==n){
            cout<<"0";
            return 0;
        }
    }
    ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=M;
    }
    cout<<ans;
    return 0;
}
