#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,mod=998244353;
int n,m,c[maxn],p[maxn];
string s;
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),cin>>s;
	for(int i=1;i<=n;i++)c[p[i]=i]=read();
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='0'||cnt>=c[p[i]])cnt++;
		if(n-cnt>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans);
	return 0;
}
