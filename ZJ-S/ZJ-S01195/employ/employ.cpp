#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,ans,c[1005],id[1005];
bool vis[1005];
char st[1005];
void dfs(int x){
	if(x>n){
		int fail=0;
		for(int i=1;i<=n;i++){
			if(fail>=c[id[i]])fail++;
			else if(st[i]=='0')fail++;
		}
		if(n-fail>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			id[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(st[i]=='1'){
				int res=1;
				for(int j=1;j<=n;j++)res=1ll*res*j%M;
				printf("%d\n",res);
				return 0;
			}
		}
		puts("0");
		return 0;
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		if(st[i]=='0'){
			f=1;
			break;
		}
	}
	if(!f){
		int res=1;
		for(int j=1;j<=n;j++)res=1ll*res*j%M;
		printf("%d\n",res);
		return 0;
	}
	for(int i=1;i<=n;i++)id[i]=i;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
