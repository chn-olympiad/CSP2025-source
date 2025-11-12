//RP++ 1= Please!
//60pts
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
const int maxn=1e5+5,cmaxn=405;
int T,n,ans,a[maxn][3],b[maxn],f[cmaxn][cmaxn][cmaxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();bool SubB=1;ans=0;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++){
			a[i][j]=read();
			if(j&&a[i][j])SubB=0;
			if(!j)b[i]=a[i][j];
		}
		if(SubB){
			sort(1+b,1+b+n,[](int x,int y){return x>y;});
			for(int i=1;i<=n/2;i++)ans+=b[i];
		}
		else {
			memset(f,0,sizeof(f));
			for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)for(int k=0;k<=n/2&&i+j+k<=n;k++){
				if(!i&&!j&&!k)continue;
				int id=i+j+k;
				if(i)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[id][0]);
				if(j)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[id][1]);
				if(k)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[id][2]);
			}
			for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)ans=max(ans,f[i][j][n-i-j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}