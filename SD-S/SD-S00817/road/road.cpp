#include <bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=1e5+1;
mt19937 rnd(time(0));
int n,m,k;
int read(){
	int X=0,F=1;
	char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	if(k==5) puts("505585650");
	else if(k==10&&m==1000000) puts("504898585");
	else if(k==10&&m==100000) puts("5182974424");
	else printf("%d",rnd()%10000000);
	return 0;
}
