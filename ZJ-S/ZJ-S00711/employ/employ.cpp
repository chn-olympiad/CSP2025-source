#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[510],k[510],x[510],v[510];
long long c[510],ans;
string s;
void dfs(int l,int sum,int lo){
	if(n-l+1<m-sum)return;
	if(sum>=m){
		ans+=c[n-l+1],ans%=mod;
		return;
	}
	if(l>n)return;
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1;
			int o=(s[l]=='1'&&a[i]>=lo);
			dfs(l+1,sum+o,(o==1?1:lo+1));
			v[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m),cin>>s,s=" "+s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	c[0]=1;for(int i=1;i<=n;i++)c[i]=c[i-1]*i,c[i]%=mod;
	dfs(1,0,1);
	printf("%lld",ans);
	return 0;
}
