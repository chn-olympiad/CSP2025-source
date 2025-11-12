#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[510],v[510],mod=998244353,ans,n,m,maxn;
string s;
int jc(int x){
	int sum=1;
	for (int i=1;i<=x;i++) sum=sum*i%mod;
	return sum;
}
void dfs(int x,int s1,int s2){
	if (s1<m&&s2>=maxn) return;
	if (s1>=m){
		ans=(ans+jc(n-x+1))%mod;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!v[i]){
			v[i]=1;
			if (s[x-1]=='1'&&c[i]>s2)
				dfs(x+1,s1+1,s2);
			else dfs(x+1,s1,s2+1);
			v[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (maxn<c[i]) maxn=c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}