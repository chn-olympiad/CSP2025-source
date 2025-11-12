#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
short n,m,c[505];char s[505];int ans;bool vis[505];
void dfs(int step,int ou){
	if(n-ou<m)return;
	if(step==n){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(ou>=c[i]||s[step]=='0')
				dfs(step+1,ou+1);
			else
				dfs(step+1,ou);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%hd %hd",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}