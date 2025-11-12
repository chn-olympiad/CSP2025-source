#include <iostream>
#include <algorithm>
using namespace std;
const int N=510,mod=998244353;
char diff[N];
int c[N],p[N];
int n,m;
bool check() {
	for(int i=1;i<=n;i++) {
		if(diff[i]=='0') return 0;
	}
	return 1;
}
int C[N][N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(diff+1);
	bool fg=0,fg1=1;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i,fg|=(c[i]=='1'),fg1&=(c[i]=='1');
	if(check() || (fg&&m==1)) {
		int ans=1;
		for(int i=1;i<=n;i++) ans=(1ll*ans*i)%mod;
		cout<<ans;
		return 0;
	}
	if(fg1 && m==n) {
		puts("1");
		return 0;
	}
	int ans=0;
	do {
		int add=0,ot=0;
		for(int i=1;i<=n;i++) {
			int x=p[i]; //id
			if(add>=c[x]) add++;
			else if(diff[i]=='0') add++;
			else ot++;
		}
		if(ot>=m) ans=(ans+1>=mod?ans+1-mod:ans+1);
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}