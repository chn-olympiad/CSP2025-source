#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int n,m,a[105],b;
bool cmp(int x,int y){return y<x;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	b=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==b){b=i;break;}
	printf("%d ",(b-1)/n+1);
	if(((b-1)/n+1)&1) printf("%d",((b-1)%n)+1);
	else printf("%d",m-((b-1)%n));
	return 0;
}