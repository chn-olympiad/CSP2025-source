#include<bits/stdc++.h>
using namespace std;
const int maxm=2e7+5;
const int maxn=1e4+5;
long long ans,n,a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f*=-1;ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
 	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),read(),read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)  ans+=a[i];
	printf("%d\n",ans);
	return 0;
}
/*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
*/
