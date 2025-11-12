#include<bits/stdc++.h>
using namespace std;
#define int long long
int st;
const int mcx=5005;
const int mod=998244353;
int n,a[mcx],m,c[mcx][mcx];
long long ans;
int qp[mcx];
bool v[mcx];
void dfs(int step){
	if(step>=m+1){
		int ma=INT_MIN,sum=0;
		for(int i=1;i<=m;i++)ma=max(ma,a[qp[i]]),sum+=a[qp[i]];
		if(sum>ma*2){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]||i<qp[step-1])continue;
		v[i]=1;
		qp[step]=i;
		dfs(step+1);
		v[i]=0;
		qp[i]=0;
	}
}
int ed;
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	if(maxn<=1){
		c[0][0]=1;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(i==0&&j==0)continue;
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(m=3;m<=n;m++)dfs(1);
	cout<<ans<<'\n';
	return 0;
}