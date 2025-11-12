#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],cnt,ans=1;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	if(n-cnt<m) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cout<<ans<<endl;
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
