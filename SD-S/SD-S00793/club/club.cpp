#include<bits/stdc++.h>
using namespace std;
int n,t,cnt1,cnt2,cnt3,m3;
long long ans;
struct abc
{
	int a;
	int b;
	int c;
	int m1,m2;
}s[200005];
bool cmp(abc e,abc f)
{
	return e.m1-e.m2>f.m1-f.m2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n;
		memset(s,0,sizeof(s));
		for (int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].m1=max(s[i].a,max(s[i].b,s[i].c));
			m3=min(s[i].a,min(s[i].b,s[i].c));
			if (s[i].a!=m3 && s[i].a!=s[i].m1)
			{
				s[i].m2=s[i].a;
			}
			if (s[i].b!=m3 && s[i].b!=s[i].m1)
			{
				s[i].m2=s[i].b;
			}
			if (s[i].c!=m3 && s[i].c!=s[i].m1)
			{
				s[i].m2=s[i].c;
			}
		}
		sort(s+1,s+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (s[i].a>=max(s[i].b,s[i].c))
			{
				if (cnt1<n/2)
				{
					cnt1++;
					ans+=s[i].a;
					continue;
				}
				if (s[i].b>=s[i].c)
				{
					cnt2++;
					ans+=s[i].b;
					continue;
				}
				cnt3++;
				ans+=s[i].c;
			}
			else if (s[i].b>=max(s[i].a,s[i].c))
			{
				if (cnt2<n/2)
				{
					cnt2++;
					ans+=s[i].b;
					continue;
				}
				if (s[i].a>=s[i].c)
				{
					cnt1++;
					ans+=s[i].a;
					continue;
				}
				cnt3++;
				ans+=s[i].c;
			}
			else if (s[i].c>=max(s[i].b,s[i].a))
			{
				if (cnt3<n/2)
				{
					cnt3++;
					ans+=s[i].c;
					continue;
				}
				if (s[i].a>=s[i].b)
				{
					cnt1++;
					ans+=s[i].a;
					continue;
				}
				cnt2++;
				ans+=s[i].b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
