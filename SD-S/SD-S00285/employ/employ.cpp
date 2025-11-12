#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[509],f,da=1,aa[19];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f=1;break;
		}
	}
	if(!f){
		for(int i=1;i<=n;i++){
			da=da*i%mod;
		}
		cout<<da;
	}
	else cout<<0;
	return 0;
}

