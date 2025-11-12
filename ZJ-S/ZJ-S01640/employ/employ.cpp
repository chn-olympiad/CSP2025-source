//RP++ 1= Please!
//8pts
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const int maxn=505,TT=998244353;
int n,m,ans,a[maxn],c[maxn],p[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='1'&&ch!='0')ch=getchar();
		a[i]=(ch=='0');p[i]=i;
	}
	for(int i=1;i<=n;i++)c[i]=read();
	do{
		int sum=0,now=0;
		for(int i=1;i<=n;i++){
			if(sum<c[p[i]]&&!a[i])now++;
			else sum++;
		}
		if(now>=m)ans=(ans+1)%TT;
	}while(next_permutation(1+p,1+p+n));
	printf("%d\n",ans);
	return 0;
}