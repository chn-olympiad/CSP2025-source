#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,mod=998244353;
int n,m,ans,c[maxn],a[maxn];
char s[maxn];
bool flag[maxn];
void check(){
	int sum=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='0'||sum>=c[a[i]])sum++;
	if(n-sum>=m)ans++;
}
void dfs(int x){
	if(x>n)return check();
	for(int i=1;i<=n;i++)
		if(!flag[i])flag[i]=true,a[x]=i,dfs(x+1),flag[i]=false;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}


