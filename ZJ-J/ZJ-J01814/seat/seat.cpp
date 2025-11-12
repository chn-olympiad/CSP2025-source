#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],aid,id,c,r;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	aid=a[1];
	sort(a+1,a+1+n*m);reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i]==aid) id=i;
	c=(id+n-1)/n;
	if(c%2==0) r=n-(id%n)+1;
	else r=id%n;
	if(c%2==0&&r==0) r=1;
	if(c%2==1&&r==0) r=n; 
	printf("%d %d\n",c,r);
	return 0;
}

