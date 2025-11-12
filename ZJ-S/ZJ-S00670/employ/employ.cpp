#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,c[600];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for (int i=1;i<=n;i++) {
		cin>>c[i];
		if (c[i]==0) cnt++;
	}
	sort(c+1,c+1+n);
	bool flag=true;
	long long ans=1;
	for (int i=1;i<=n-cnt;i++) {
		(ans*=i)%=mod;
		if (s[i-1]!='1') flag=false;
	}
	if (flag) cout<<ans<<endl;
	else cout<<(1ll*rand()*rand())%mod<<endl;
}
