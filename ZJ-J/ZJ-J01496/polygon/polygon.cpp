#include<bits/stdc++.h>
using namespace std;
int n,x,a[5005],ans=0;

int read(){
	int f=1,cnt=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))cnt=cnt*10+ch-'0',ch=getchar();
	return f*cnt;
}

void bfs(int j,int v,int maxn,int k){
//	printf("%d %d %d %d\n",j,v,maxn,k);
	for(int i=j+1;i<=n;i++){
		int x=max(maxn,a[i]),y=v+a[i];
		if(k+1>=3&&x*2<y) ans++;
		bfs(i,y,x,k+1);
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n-2;i++) ans%=998244353,bfs(i,a[i],a[i],1);
	printf("%d",ans);
}
