#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxv=1<<20|5;
int n,k,s[maxn],mx[maxv],f[maxn];
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)s[i]=s[i-1]^read();
	memset(mx,192,sizeof mx);mx[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],mx[s[i]^k]+1);
		mx[s[i]]=max(mx[s[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
