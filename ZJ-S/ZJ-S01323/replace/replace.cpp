#include <bits/stdc++.h>
using namespace std;
struct point
	{
		long long l,r;
		string s,t;
	}h[1001000];
long long n,m,sum,l,r;
string a,b,aa,bb;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		{
			cin>>a>>b;
			int len=a.size();
			l=0,r=a.size()-1,sum=1;
			while(a[l]==b[l]) l++;
			while(a[r]==b[r]) r--;
			for(int j=l;j<=r;j++) sum*=(int)a[j],sum%=1000000;
			while(h[sum].s.size()!=0) sum++;
			h[sum].s=a,h[sum].t=b;
			h[sum].l=l,h[sum].r=len-1-r;
		}
	for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			if(a.size()!=b.size())continue;
			l=0,r=a.size()-1,sum=1;
			while(a[l]==b[l]) l++;
			while(a[r]==b[r]) r--;
			int ans=0,f=0;
			for(int j=l;j<=r;j++) sum*=(int)a[j],sum%=1000000;
			while(h[sum].s.size()!=0)
				{
					f=0;
					if(h[sum].s.size()>a.size())
						{
							sum++;
							continue;
						}
					for(int j=l-h[sum].l;j<=r+h[sum].r;j++)
						if(a[j]!=h[sum].s[j-l+h[sum].l]) f=1;	
					for(int j=l-h[sum].l;j<=r+h[sum].r;j++)
						if(b[j]!=h[sum].t[j-l+h[sum].l]) f=1;
					if(f==0) ans++;
					sum++;
				}
			printf("%d\n",ans);
		}
	return 0;
}