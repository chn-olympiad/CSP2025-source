#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5010],cnt,F,sum;
int f[5010][5010];
void dfs(int t,int mx,int ct,int h){
	if(ct==t){
		int x=lower_bound(a+1,a+n+1,h)-a-1;
		cnt=(cnt+x-mx)%MOD;
		return ;
	}
	if(mx+t-ct>n) return ;
	for(int i=mx+1;i<=n;i++) dfs(t,i,ct+1,h+a[i]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) F=1;
	}
	if(!F){
		for(int i=3;i<=n;i++) f[i][1]=i-2+f[i-1][1];
		for(int i=3;i<=n;i++) f[i][1]+=f[i-1][1];
		for(int i=3;i<=n;i++)
			for(int j=2;j<=i-2;j++)
				f[i][j]=f[i-1][j-1]+f[i-1][j-1];
		for(int i=3;i<=n;i++)
			for(int j=1;j<=i-2;j++)
				sum=(sum+f[i][j])%MOD;
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(i-1,0,0,0);
	cout<<cnt;
	return 0;
}