#include<bits/stdc++.h>
#define int long long
#define mod 998244353

using namespace std;

int ans,f[5005][5005],n,sum=1,a[5005],maxx,d[5005],b[5005][5005],s[5005];

void dfs(int x,int y,int step,int fff){
	if(step==x){
		int sum=0;
		for(int i=1;i<step;i++){
			sum+=s[i];
		}
		if(s[step]<sum){
			ans++;
		}
		if(ans==mod)ans=0;
		return;
	}
	for(int i=fff+1;i<=y;i++){
			s[step+1]=a[i];
			dfs(x,y,step+1,i);
		
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	for(int i=1;i<=maxx;i++){
		if(d[a[i]]>1)sum*=d[a[i]];
		sum%=mod;
	}
	sort(a+1,a+n+1);
	if(maxx==1){
		cout<<n*(n-1)*(n-2)/6;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=0;
			dfs(i,j,0,0);
			b[i][j]=ans;
			}
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]+=((f[i][j-1]%mod)+(b[i][j]%mod))%mod;
		}
		f[i+1][i]=f[i][n]%mod;
	}
	cout<<f[n][n]/sum%mod;
	return 0;
}
