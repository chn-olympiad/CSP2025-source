#include <bits/stdc++.h>
using namespace std;
struct student
{
	int a,b,c,id;
}s[100005];
bool cmp(student a,student b)
{
	if(a.a!=b.a) return a.a<b.a;
	if(a.b!=b.b) return a.b<b.b;
	if(a.c!=b.c) return a.c<b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >>n;
		const int e=n/2;
		int suma=0,sumb=0,sumc=0,ans=0;
		for(int i = 1;i <= n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].id=i;
			suma+=s[i].a,sumb+=s[i].b,sumc+=s[i].c;
		}
		sort(s+1,s+n+1,cmp);
		int sum=0;
		int pos=0;
		if(sumb==0&&sumc==0)
		{
			for(int i = n;i>=(n/2+1);i--)
			{
				ans+=s[i].a;
			}
			cout <<ans;
			continue;
		}
	}
	return 0;
}