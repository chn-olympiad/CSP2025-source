#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,a[N],ans,vis[N];
char s[N];
void dfs(int x,int kick){
	if (kick>n-m) return;
	if (x>n){ans++;return;}
	for (int i=1;i<=n;i++)
		if (vis[i]==0){
			vis[i]=1;
			if (a[i]>kick&&s[x]=='1') dfs(x+1,kick);
			dfs(x+1,kick+1);
			vis[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

