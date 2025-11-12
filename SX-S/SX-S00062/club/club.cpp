#include<bits/stdc++.h>
#define J s[j]
#define ll long long
using namespace std;
int t,n;struct memb{int a,b,c,lq;}s[100005];
bool cmp1(memb x,memb y)
{
	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b<y.b;
	return x.c<y.c;
}
bool cmp2(memb x,memb y)
{
	if(x.b!=y.b) return x.b>y.b;
	if(x.a!=y.a) return x.a<y.a;
	return x.c<y.c;
}
bool cmp3(memb x,memb y)
{
	if(x.c!=y.c) return x.c>y.c;
	if(x.b!=y.b) return x.b<y.b;
	return x.a<y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;int N=n,sum=0,as=0,bs=0,cs=0;
		for(int i=1;i<=n;i++)
		{
			s[i].lq=0;
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		while(N)
		{
			for(int i=1;i<=3;i++)
			{
				if(i==1)sort(s+1,s+n+1,cmp1);
				if(i==2)sort(s+1,s+n+1,cmp2);
				if(i==3)sort(s+1,s+n+1,cmp3);
				for(int j=1;j<=n;j++)
				{
					if(J.lq==0)
					{
						bool f=0;
						if(i==1&&J.a>=J.b&&J.a>=J.c){f=1,sum+=J.a,as++;if(as==n/2) as=-1;}
						if(i==2&&J.b>=J.a&&J.b>=J.c){f=1,sum+=J.b,bs++;if(bs==n/2) bs=-1;}
						if(i==3&&J.c>=J.a&&J.c>=J.b){f=1,sum+=J.c,cs++;if(cs==n/2) cs=-1;}
						if(f) J.lq=1,N--;break;//cout<<N<<" "<<sum<<endl;
					}
					if(as==-1){for(int i=1;i<=n;i++)s[i].a=-1; continue;}
					if(bs==-1){for(int i=1;i<=n;i++)s[i].b=-1; continue;}
					if(cs==-1){for(int i=1;i<=n;i++)s[i].c=-1; continue;}
				}
				if(!N) break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}