#include<bits/stdc++.h>
using namespace std;
const int TT=998244353;
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int n,m,ans;
int c[505],p[505],sus;
bool s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)s[i]=getchar()-'0';
	for(int i=1;i<=n;i++){
		p[i]=i;
		c[i]=read();
	}
	do
	{
		int sus=0,fail=0;
		for(int i=1;i<=n;i++)if(!s[i]||fail>=c[p[i]])fail++;
		else sus++;
		ans+=(sus>=m);
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}
