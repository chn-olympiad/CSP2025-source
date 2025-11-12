#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
int read(){
	int ret=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
	while('0'<=ch&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int a[maxn],nl;
struct rd{
	int to,val;
	int v;
};
int p[maxn][maxn];
int n,m,k;
int ans=1<<30;
int c[15];
int d(int s){
	bool f[maxn]={0};
	f[1]=1;
	int ant=0;
	for(int t=1;t<n+k;t++){
		if(t>n&&(!(s&(1<<(t-n-1)))))continue;
		int minl=(1<<30),minj=-1;
		for(int i=1;i<=n+k;i++){
			if(!f[i])continue;//f[i]==1
			for(int j=1;j<=n+k;j++){
				if(p[i][j]<0||f[j]||(j>n&&(!(s&(1<<(j-n-1))))))continue;//f[j]==0
				if(p[i][j]<minl){
					minj=j;
					minl=p[i][j];
				}
			}
		}
		if(minj!=-1){
			f[minj]=1;
			ant+=minl;
		}
		
	}
	return ant;
}
int cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read();
	k=read();
	nl=n+k;
	memset(p,-1,sizeof p);
	for(int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		p[x][y]=p[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		cnt+=c[i];
		for(int j=1;j<=n;j++){
			int x=read();
			p[i+n][j]=x;
			p[j][i+n]=x;
		}
	}
	int cans=0;
	if(cnt==0){
		ans=d((1<<k)-1);
	}
	else{
		for(int tt=0;tt<1<<k;tt++){
			cans=0;
			for(int ii=1;ii<=k;ii++){
				if(tt&(1<<ii-1))cans+=c[ii];
			}
			
			ans=min(ans,d(tt)+cans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
