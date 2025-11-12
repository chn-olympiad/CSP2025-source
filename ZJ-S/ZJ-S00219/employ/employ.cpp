/*
T3 employ.cpp
ZJ-S00219 shicj
??pts

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0'){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans<<endl;
	return 0;
}