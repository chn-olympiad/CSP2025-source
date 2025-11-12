#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,y=1;
const int mode=998244353;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f*=-1;ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
 	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)  x*=i%mode;
	for(int j=1;j<=m;j++)  y*=j%mode;
	printf("%lld\n",x/y);
	return 0;
}
/*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
*/
