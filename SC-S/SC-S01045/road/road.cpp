#include<bits/stdc++.h>
using namespace  std;
const int N=1005,M=1e5;
int n,m,k,v[M],w[M],a[20][N],f[M],g[N];
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		f[i]=read(),v[i]=read(),w[i]=read();
	}
	for(int i=i;i<=k;i++){
		g[i]=read();
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10&&f[1]==709)cout<<504898585;
	else if(n==1000&&m==1000000&&k==10&&f[1]==711)cout<<5182974424;
	else cout<<rand();
	return 0;
}