#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,tt,fl,s,c[1001],ff[1001],f[1001];
char a[1001];
const int mod=998244353;
void pd(){
	int i,ss=0,v=0;
	for(i=1;i<=n;i++)
		if(ss>=c[f[i]]){
			ss++;
			continue;
		}
		else{
			if(a[i]=='1') v++;
			else ss++;
		}
	if(v>=m) s=(s+1)%mod;
}
void sc(int t){
	int i;
	if(t>n){
		pd();
		return ;
	}
	for(i=1;i<=n;i++)
		if(ff[i]==0){
			ff[i]=1;
			f[t]=i;
			sc(t+1);
			ff[i]=0;
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a+1;
	for(i=1;i<=n;i++)
		if(a[i]=='1') tt++;
	for(i=1;i<=n;i++) cin>>c[i];
	if(tt==n){
		for(i=1;i<=n;i++)
			if(c[i]==0) fl++;
		if(n-fl<m) cout<<0;
		else{
			s=1;
			for(i=1;i<=n;i++) s=s*i%mod;
			cout<<s;
		}
		return 0;
	}
	sc(1);
	cout<<s;
	return 0;
}
