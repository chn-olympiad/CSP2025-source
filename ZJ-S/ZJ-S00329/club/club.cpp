#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int n,T,ans,f[205][205][205];
struct mine{
	int a,b,c;
}a[100005];
bool cmp1(mine x,mine y){
	return x.a>y.a;
}
bool cmp2(mine x,mine y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int A=0;
		for(int i=1;i<=n;i++)
		a[i].a=read(),a[i].b=read(),a[i].c=read(),
		A+=a[i].b;
		if(!A){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=(n>>1);i++) A+=a[i].a;
			printf("%d\n",A);
			continue;
		}
		int ans=0;
		memset(f,0,sizeof f);
		int nn=n>>1;
		for(int i=0;i<=nn;i++) for(int j=0;j<=nn;j++) for(int k=0;k<=nn&&i+j+k<=n;k++){
			if(i>0) f[i][j][k]=max(f[i-1][j][k]+a[i+j+k].a,f[i][j][k]);
			if(j>0) f[i][j][k]=max(f[i][j-1][k]+a[i+j+k].b,f[i][j][k]);
			if(k>0) f[i][j][k]=max(f[i][j][k-1]+a[i+j+k].c,f[i][j][k]);
		}
		for(int i=0;i<=nn;i++)
		for(int j=0;j<=nn;j++)
		ans=max(ans,f[i][j][n-i-j]);
		printf("%d\n",ans);
	}
	return 0;
}
