#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
int n,m,q,a[505],c[505],jc[505],p=998244353;
int tf=1,gf;
map<int,int>mp;
char x;
int dfs(int t,int u,int h){
	int s=0;
	//cout<<u<<" "<<t<<" "<<h<<"\n";
	if(mp[(h<<n)+t])return mp[(h<<n)+t];
	if(h>=m){
		s=mp[(h<<n)+t]=jc[n-u+1];
		return s;
	}
	if(u-1-h>n-m)return 0;
	for(int i=1;i<=n;i++)if((t>>(i-1))%2==0){
		if(c[u]==0||u-h-1>=a[i])s+=dfs(t|(1<<(i-1)),u+1,h);
		else s+=dfs(t|(1ll<<(i-1)),u+1,h+1);	
	}
	return s;
}
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%p;
	if(m==n){
		q=1;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x-'0'==0)q=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0)q=0;
		}
		cout<<jc[n]*q;
		return 0;
	}
	if(m==1){
		int s=0,k=1,h=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			c[i]=x-'0';
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)if(c[i]){
			h=0;
			for(int j=1;j<=n;j++)if(a[j]>=i)h++;
			s+=k*h%p*jc[n-q-1]%p,s%=p,k=k*(n-h-q)%p,q++;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		c[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<dfs(0,1,0)<<"\n";
}
