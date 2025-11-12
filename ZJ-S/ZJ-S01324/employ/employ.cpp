#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[510],x,sum,f[510],bao[510];string s;
bool pd(){
	int i,mei=0,sumy=0;
	for(i=1;i<=n;i++)
		if(s[i-1]=='0') mei++;
		else
			if(mei>=a[bao[i]]) mei++;
			else sumy++;
	return sumy>=m;
}
void dfs(int x){
	if(x==n+1){
		if(pd()) sum=(sum+1)%998244353;
		return ;
	}
	int i;
	for(i=1;i<=n;i++)
		if(!f[i]){
			f[i]=1,bao[x]=i;dfs(x+1);f[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",sum%998244353);
	return 0;
}