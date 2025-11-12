#include<bits/stdc++.h>
using namespace std;
struct data{
	int a,b,c,h;
}f[100005];
int t;
bool comp(data x,data y)
{
	if(x.c==y.c)return x.a>y.a;
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		int n,x[100005],y[100005],z[100005],bo[5],s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			f[i].a=max(x[i],max(y[i],z[i]));
			if(x[i]==max(x[i],max(y[i],z[i])))
			 {
			 	f[i].b=max(y[i],z[i]);
				f[i].h=1;
				f[i].c=f[i].a-f[i].b;
			 	continue;
			  } 
			if(y[i]==max(x[i],max(y[i],z[i])))
			 {
			 	f[i].b=max(x[i],z[i]);
			 	f[i].h=2;
			 	f[i].c=f[i].a-f[i].b;
				continue;
			  } 
			  if(z[i]==max(x[i],max(y[i],z[i])))
			 {
			 	f[i].b=max(y[i],x[i]);
			 	f[i].h=3;
			 	f[i].c=f[i].a-f[i].b;
				continue;
			} 
		}
		sort(f+1,f+n+1,comp);
		memset(bo,0,sizeof(bo));
		for(int i=1;i<=n;i++)
		{
			if(bo[f[i].h]<n/2)
			{
				s+=f[i].a;
				bo[f[i].h]++;
			}
			else
			  s+=f[i].b;
		}
		printf("%d\n",s);
	}
	return 0;
} 

