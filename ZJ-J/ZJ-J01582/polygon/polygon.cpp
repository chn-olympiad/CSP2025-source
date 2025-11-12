#include <bits/stdc++.h>
using namespace std;
const int maxn=5005,TT=998244353;
int n,k,a[maxn],ans,f[(1<<20)+5],M,C[maxn][maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),M=max(M,a[i]);
	if(M==1){
		C[1][1]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			if(i==1&&j==1) continue;
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%TT;
		}
		for(int i=3;i<=n;i++)
		ans=(ans+C[n][i])%TT;
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=(1<<n);i++){
		int sum=0,mx=0,tot;
		for(int j=1;j<=n;j++)
		if((i>>j-1)&1) sum+=a[j],mx=max(mx,a[j]),tot++;
		if(mx*2>=sum) continue;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}