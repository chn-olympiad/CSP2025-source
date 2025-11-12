#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=500+5,inf=1e18,mod=998244353;
int n,m;
char c[N];
int a[N];
int f[(1<<18)][19];
int p[(1<<18)];
int cnt[(1<<18)];
bool cmp(int x,int y){
	return cnt[x]<cnt[y];
}
void sl(){
	cin>>n>>m;
	cin>>c+1;
	bool fl=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!a[i])fl=0;
		if(c[i]=='0')fl=0;
	}
	if(n==m){
		if(fl){
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans;
		}
		else cout<<0;
		return ;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((1<<j)&i)cnt[i]++;
		}
		p[i]=i;
	}
	sort(p,p+(1<<n),cmp);
	f[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int i=p[s];
		for(int j=0;j<n;j++){
			for(int k=1;k<=n;k++){
				if((1<<k-1)&i)continue;
				int flag=0;
				if(j>=a[k]||c[cnt[i]+1]=='0')flag=1;
				f[i|(1<<k-1)][j+flag]+=f[i][j];
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n-m;j++)ans+=f[(1<<n)-1][j];
//	for(int j=0;j<=n;j++)cout<<f[(1<<n)-1][j]<<" ";
	cout<<ans<<"\n";
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int tt=1;
//	cin>>tt;
	while(tt--)sl();
	return 0;
}

