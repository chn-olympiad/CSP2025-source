#include<bits/stdc++.h>
using namespace std;
const int mx=1e5;
struct noden
{
	int a,b,c;
}nd,arr[mx+10],brr[mx+10],crr[mx+10];
int read()
{
	int v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=v*10+(ch-'0');
		ch=getchar();
	}
	return v;
}
bool compa(const noden &aa,const noden &bb)
{
	return min(aa.a-aa.b,aa.a-aa.c)<min(bb.a-bb.b,bb.a-bb.c);
}
bool compb(const noden &aa,const noden &bb)
{
	return min(aa.b-aa.a,aa.b-aa.c)<min(bb.b-bb.a,bb.b-bb.c);
}
bool compc(const noden &aa,const noden &bb)
{
	return min(aa.c-aa.a,aa.c-aa.b)<min(bb.c-bb.a,bb.c-bb.b);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,tt,n,ans,cnta,cntb,cntc;
	tt=read();
	while(tt--)
	{
		n=read();
		cnta=cntb=cntc=ans=0;
		for(i=1;i<=n;++i)
		{
			nd.a=read();nd.b=read();nd.c=read();
			if(nd.a>=nd.b&&nd.a>=nd.c)
			{
				arr[++cnta]=nd;
				ans+=nd.a;
			}
			else if(nd.b>=nd.a&&nd.b>=nd.c)
			{
				brr[++cntb]=nd;
				ans+=nd.b;
			}
			else
			{
				crr[++cntc]=nd;
				ans+=nd.c;
			}
		}
		if(cnta>n/2)
		{
			sort(arr+1,arr+1+cnta,compa);
			for(i=1;i<=cnta-n/2;++i)
				ans-=min(arr[i].a-arr[i].b,arr[i].a-arr[i].c);
		}
		else if(cntb>n/2)
		{
			sort(brr+1,brr+1+cntb,compb);
			for(i=1;i<=cntb-n/2;++i)
				ans-=min(brr[i].b-brr[i].a,brr[i].b-brr[i].c);
		}
		else if(cntc>n/2)
		{
			sort(crr+1,crr+1+cntc,compc);
			for(i=1;i<=cntc-n/2;++i)
				ans-=min(crr[i].c-crr[i].a,crr[i].c-crr[i].b);
		}
		printf("%d\n",ans);
	}
	return 0;
}
