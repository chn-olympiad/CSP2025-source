#include<bits/stdc++.h>
using namespace std;
const int N=5e2+100,mod=998244353;
int n,m,s[N],c[N],ans,fq,lq;
char x;
bool vis[N];
void dfs(int x){
	if(fq>n-m)return;
	if(x==n+1){
		if(lq>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int f=fq,l=lq;
			if(fq>=c[i])fq++;
			else if(s[x])lq++;
			else fq++;
			dfs(x+1);
			vis[i]=0;
			fq=f,lq=l;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %c",&x);
		if(x=='1')s[i]=1;
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
}