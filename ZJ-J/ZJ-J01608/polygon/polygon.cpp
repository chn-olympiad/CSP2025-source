//RP++ 300+ Please!
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#define int long long
using namespace std;
const int maxn=5005,TT=998244353;
int n,ans,a[maxn],f[maxn],vis[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(1+a,1+a+n);
	f[0]=f[a[1]+a[2]]=1;
	if(a[1]==a[2])f[a[1]]=2;
	else f[a[1]]=f[a[2]]=1;
	for(int i=3;i<=n;i++){
		int all=0,lst=1;
		for(int j=1;j<i;j++)lst=lst%TT*(i-j)/j,all=(all+lst)%TT;
		for(int j=1;j<=a[i];j++)all=(all-f[j]+TT)%TT;
		for(int j=5000;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%TT;
		vis[a[i]]=max(vis[a[i]],all);
	}
	for(int i=1;i<=5000;i++)ans=(ans+vis[i])%TT;
	printf("%d\n",ans);
	return 0;
}