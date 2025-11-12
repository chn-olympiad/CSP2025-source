#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],flag[505],ans=0,mod=998244353;
string st;
void dfs(int now,int k){
	if(now>n){
		if(n-k>=m) ans++;
		if(ans==mod) ans=0;
		return;
	}
	for(int i=1;i<=n;i++)
		if(flag[i]!=1){
			flag[i]=1;
			if(k>=c[i]||st[now]=='0') dfs(now+1,k+1);
			else dfs(now+1,k);
			flag[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>st;
	st='*'+st;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) flag[i]=0;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}