#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mode=998244353;
int k,n,a[maxn],vis[maxn],b[maxn],ans,cnt,mx,m,x=1,y=1,z;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void dfs(int x,int L,int m,int q){
	if(x>=4&&L>2*m) {
//		for(int i=1;i<x;i++) printf("%d ",b[i]);
//		printf("%d\n",L);
		++cnt;
		cnt%=mode;
	}
	if(x==n+1||q>n) return;
	for(int i=q;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=a[i];
//			printf("%d\n",i);
			dfs(x+1,L+a[i],max(m,a[i]),i+1);
			vis[i]=0;
		}
	} 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),mx=max(mx,a[i]);
	if(mx==1) {
		for(int i=3;i<=n;i++) {
			x=1,y=1;
			for(int j=1;j<=i;j++) x*=(n-j+1)%mode;
			for(int j=1;j<=i;j++) y*=j%mode;
			ans+=x/y%mode;
//			printf("%d %d\n",x,y);
		}
		return printf("%d\n",ans),0;
	}
	else dfs(1,0,0,1);
 printf("%d\n",cnt);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
