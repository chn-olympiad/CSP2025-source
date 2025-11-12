#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
const int maxn=15;
int n,m,s[maxn*maxn],S,c,r;
bool cmp(int a,int b){
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)s[i]=read();
	S=s[1];
	sort(s+1,s+1+n*m,cmp);
	int pos;
	for(pos=1;s[pos]!=S;pos++);
//	printf("%d\n",pos);
//	for(int i=1;i<=n*m;i++)printf("%d ",s[i]);
//	printf("\n");
	if(n==1)c=pos;
	else c=(pos+n-1)/n;
	if(m==1)r=pos;
	else{
		if(c&1)r=pos%n==0?n:pos%n;
		else r=n-(pos%n==0?n:pos%n)+1;
	}
	printf("%d %d",c,r);
	return 0;
}
