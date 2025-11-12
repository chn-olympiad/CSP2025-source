#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,r,id(1),x(1),y;
inline int read(){
	int ret(0),f(1);char ch(getchar());
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n*m;++i){
		l=read();
		if(l>k) ++id;
	}
	for(;id>n;) id-=n,++x;
	if(x%2==0) y=n-id+1;
	else y=id;
	printf("%d %d\n",x,y);
	return 0;
}