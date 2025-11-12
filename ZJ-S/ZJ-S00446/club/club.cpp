#include<bits/stdc++.h>
using namespace std;
struct Peo
{
	int a,b,c;
};
const int N=1e5+10;
Peo p[N];
int mns[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
		int cnta=0,cntb=0,cntc=0,cur=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int a=p[i].a,b=p[i].b,c=p[i].c;
			if(a>=b&&a>=c)
			{
				cnta++;
				ans+=1ll*a;
			}
			else if(b>=a&&b>=c)
			{
				cntb++;
				ans+=1ll*b;
			}
			else
			{
				cntc++;
				ans+=1ll*c;
			}
		}
		int left=0;
		if(cnta>(n/2))
		{
			left=cnta-(n/2);
			for(int i=1;i<=n;i++)
			{
				int a=p[i].a,b=p[i].b,c=p[i].c;
				if(a>=b&&a>=c)
				{
					cur++;
					if(b>=c) mns[cur]=(a-b);
					else mns[cur]=(a-c);
				}
			}
		}
		else if(cntb>(n/2))
		{
			left=cntb-(n/2);
			for(int i=1;i<=n;i++)
			{
				int a=p[i].a,b=p[i].b,c=p[i].c;
				if(b>=a&&b>=c)
				{
					cur++;
					if(a>=c) mns[cur]=(b-a);
					else mns[cur]=(b-c);
				}
			}
		}
		else if(cntc>(n/2))
		{
			left=cntc-(n/2);
			for(int i=1;i<=n;i++)
			{
				int a=p[i].a,b=p[i].b,c=p[i].c;
				if(c>=a&&c>=b)
				{
					cur++;
					if(a>=b) mns[cur]=(c-a);
					else mns[cur]=(c-b);
				}
			}
		}
		if(cur==0) cout<<ans<<endl;
		else
		{
			sort(mns+1,mns+cur+1);
			for(int i=1;i<=left;i++) ans-=1ll*mns[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
