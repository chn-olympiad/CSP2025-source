#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{
	int a,b,c,zd,cd,z,f;
}x[maxn];
int n,t,as,bs,cs,ans;
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	ans=0;
	  	as=0;
	  	bs=0;
	  	cs=0;
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
	  	  	if(x[i].a>x[i].b&&x[i].a>x[i].c)
	  	  	  {
	  	  	  	x[i].f=1;
	  	  	  	x[i].zd=x[i].a;
	  	  	  	x[i].cd=max(x[i].b,x[i].c);
	  	  	  	as++;
			  }
			else
			  {
			  	if(x[i].b>x[i].c)
			  	  {
			  	  	x[i].f=2;
			  	  	x[i].zd=x[i].b;
	  	  	  		x[i].cd=max(x[i].a,x[i].c);
	  	  	  		bs++;
				  }
				else
				  {
				  	x[i].f=3;
				  	x[i].zd=x[i].c;
	  	  	  		x[i].cd=max(x[i].a,x[i].b);
	  	  	  		cs++;
				  }
			  }
			ans=ans+x[i].zd;
			x[i].z=x[i].zd-x[i].cd;
		  }
		sort(x+1,x+n+1,cmp);
		if(as>n/2)
		  {
		  	for(int i=1;as>n/2;i++)
		  	  if(x[i].f==1)
		  	    {
		  	    	ans=ans-x[i].z;
		  	    	as--;
				}
		  }
		if(bs>n/2)
		  {
		  	for(int i=1;bs>n/2;i++)
		  	  if(x[i].f==2)
		  	    {
		  	    	ans=ans-x[i].z;
		  	    	bs--;
				}
		  }
		if(cs>n/2)
		  {
		  	for(int i=1;cs>n/2;i++)
		  	  if(x[i].f==3)
		  	    {
		  	    	ans=ans-x[i].z;
		  	    	cs--;
				}
		  }
		printf("%d\n",ans);
	  }
	return 0;
}/*1
2
10 9 8
4 0 0*/