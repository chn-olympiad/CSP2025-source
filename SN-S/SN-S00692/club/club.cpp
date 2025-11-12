#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,ai,bi;
struct node
{
	int a,b,c,id;
}s[N];
node aa[N],bb[N];
bool cmpa(node x,node y)
{
	return x.a>y.a;
}
bool cmpba(node x,node y)
{
	return x.a<y.a;
}
bool cmpbb(node x,node y)
{
	return x.b<y.b;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0 || s[i].c!=0) f=false;
			s[i].id=i;
		}
		if(f)
		{
			sort(s+1,s+n+1,cmpa);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=s[i].a;
			}
			cout<<ans<<"\n";
		}
		else
		{
			int cnta=0,cntb=0,nn=n/2,ans=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i].a>=s[i].b)
				{
					cnta++;
					aa[++ai]=s[i];
				}
				else
				{
					cntb++;
					bb[++bi]=s[i];
				}
			}
			if(cnta>nn)
			{
				sort(aa+1,aa+ai+1,cmpba);
				for(int i=1;i<=cnta;i++)
				{
					ans+=aa[i].a;
				}
				for(int i=1;i<=cntb;i++)
				{
					ans+=bb[i].b;
				}
				for(int i=1;i<=cnta-nn;i++)
				{
					//bb[++bi]=aa[i];
					ans-=aa[i].a;
					ans+=aa[i].b;
					//cntb++;
				}
				cnta=nn;
			}
			else if(cntb>nn);
			{
				sort(bb+1,bb+bi+1,cmpbb);
				for(int i=1;i<=cnta;i++)
				{
					ans+=aa[i].a;
				}
				for(int i=1;i<=cntb;i++)
				{
					ans+=bb[i].b;
				}
				for(int i=1;i<=cntb-nn;i++)
				{
					//aa[++bi]=bb[i];
					ans-=bb[i].b;
					ans+=bb[i].a;
					//cnta++;
				}
				cntb=nn;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
