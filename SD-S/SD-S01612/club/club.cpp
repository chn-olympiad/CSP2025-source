#include<bits/stdc++.h>
#define m(a) memset(a,0,sizeof(a))
#define ll long long
using namespace std;
const int NN=1e5+10;
int T;
int n,m,a[NN][5],t[NN],t1[NN],t2[NN],b;
struct node{
	int c,m;
}p[NN]; 
bool mycmp(node a,node b)
{
	return a.c<b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		m=n/2;
		b=0;
		m(a);
		m(t);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2])
			{
				t1[i]=1;
			    t2[i]=2;
			}
			else
			{
				t1[i]=2;
			    t2[i]=1;
			} 
			if(a[i][3]>a[i][t1[i]])
			{
				t2[i]=t1[i];
				t1[i]=3;
			}
			else if(a[i][3]>a[i][t2[i]])
			{
				t2[i]=3;
			}
			t[t1[i]]++;
			p[i].c=a[i][t1[i]]-a[i][t2[i]];
			ans+=a[i][t1[i]];
			p[i].m=t1[i];
		}
		for(int j=1;j<=3;j++)
		{
			if(t[j]>n/2)
			{
				b=j;
			}
		}
		if(b==0) printf("%lld\n",ans);
		else
		{
			sort(p+1,p+n+1,mycmp); 
			ll k=0;
			int y=0;
			for(int i=1;i<=n;i++)
			{
				if(y==t[b]-n/2) break;
				if(p[i].m==b)
				{
					k+=p[i].c;
					y++;
				}
			}
			printf("%lld\n",ans-k);
		}
	}
	return 0;
}

