#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],d[505],ans;
bool vis[505];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void DFS(int num){
	if(num==n){
//		for(int i=1;i<=n;i++) printf("%d ",d[i]);
//		printf("\n");
		int x=0,y=0;
		for(int i=1,j=1;i<=n;i++){
			if(x>=a[d[i]]){
				x++;
				continue;
			}
			if(b[i]==0){
				x++,j++;
				continue;
			}
			y++,j++;
		}
		if(y>=m){
			ans++,ans%=998244353;
//			for(int i=1;i<=n;i++) printf("%d ",a[d[i]]);
//			printf("\n");
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int x=num+1;
		vis[i]=1,d[x]=i;
		DFS(x);
		vis[i]=0,d[x]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='0'&&ch!='1') continue;
		b[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) a[i]=read();
	DFS(0);
	printf("%d\n",ans);
	return 0;
}
