#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],R,rk;
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==R){rk=i;break;}
	int r=rk%n?rk%n:n,c=(rk+n-1)/n;
	if(!(c&1))r=n-r+1;
	printf("%d %d\n",c,r);
	return 0;
}
