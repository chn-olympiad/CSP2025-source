#include<bits/stdc++.h>
using namespace std;
const int N=510,P=998244353;
int n,m,ans,c[N],v[N],p[N];char s[N];
void dfs(int st){
	if(st==n+1){
		int d=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||d>=c[v[i]])d++;
			else sum++;
		}
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!p[i]){
			p[i]=1;
			v[st]=i;
			dfs(st+1);
			p[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0; 
}