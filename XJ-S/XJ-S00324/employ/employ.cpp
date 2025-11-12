#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a!=0) cnt++;
	}
	for(int i=1;i<=cnt;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}

