#include<bits/stdc++.h>
using namespace std;
#define TT 998244353
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
char s[20];
int n,m,ans,c[20],p[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read(),p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!(s[i]=='0'||i-cnt-1>=c[i])) cnt++;
		}
		(ans+=(cnt>=m))%=TT;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}
