#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,TT=998244353;
int n,k,a[maxn],f[maxn],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void dfs(int x,int y,int s){
	if(x>=2){
		for(int i=y+1;i<=n;i++){
			if(s>a[i])ans=(ans+1)%TT;
			else break;
		}
	}
	for(int i=y+1;i<=n;i++){
		dfs(x+1,i,s+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)k=1;
	}
	if(k==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%TT;
		}
		ans--;
		ans-=n;
		ans-=(n*(n-1))/2;
		printf("%d\n",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}