#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,ans;
long long s[505],c[505],p[505];
char a;
inline long long calc(int x){
	if (x==1) return 1;
	return x*calc(x-1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a;p[i]=i;
		s[i]=a-'0';
	}
	for (int i=1;i<=n;++i) cin>>c[i];
	long long ti=calc(n);
	for (int i=1;i<=ti;++i){
		int kick=0;
		for (int i=1;i<=n;++i){
			if (s[i]==0) {++kick;continue;}
			else if (kick>=c[p[i]]) {++kick;continue;}
		}
		if (kick<=n-m) {++ans;ans%=MOD;}
		next_permutation(p+1,p+n+1);
	}
	cout<<ans%MOD;
	
}
