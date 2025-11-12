#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,m,ans,fl,f[100010],p[100010],c[100010],i;
char a[100010];

void sc(int t,int s){
	int s2,i;
	if(n-s+1<m)return ;
	if(t==n+1){
		if(n-s>=m)ans++;
		return ;
	}
	for(i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			if(a[t]=='0')s2=s+1;
			else if(c[i]<=s)s2=s+1;
			else s2=s;
			sc(t+1,s2);
			f[i]=0;
		}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a+1;fl=1;
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)
		if(a[i]=='0'){
			fl=0;break;
		}
	p[0]=1;
	for(i=1;i<=n;i++)
		p[i]=p[i-1]*i%mod;
	if(fl==1){
		cout<<p[n];
		return 0;
	}
	sc(1,0);
	cout<<ans;
	return 0;
}
/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3



*/
