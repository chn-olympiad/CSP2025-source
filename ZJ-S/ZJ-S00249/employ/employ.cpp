#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
bool gt(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch-'0';
}
const int maxn=505,INF=998244353;
int n,m,c[maxn],cnt;
bool s[maxn];
int A(int x){
	if(x==0)return 1;
	int r;
	printf("%d %d\n",x,r=(int)(((long long)(x%INF)*(A(x-1)%INF))%INF));
	return r;
}

int main()
{
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)s[i]=gt();
	for(int i=1;i<=n;i++)c[i]=read();
	if(n==m)printf("0");
	else printf("%d",A(n));
	return 0;
}