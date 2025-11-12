#include<bits/stdc++.h>
using namespace std;
string s1,s2,j1,j2;
int a1[200010],a2[200010],c1[200010],d1,d2,c2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		cin>>s1;
		cin>>s2;
		int d=s1.size();
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]=='b') a1[i]=j;
			if(s2[j]=='b') a2[i]=j;
		}
		c1[i]=a2[i]-a1[i];
		a2[i]=s1.size()-a2[i]-1;
	}
	for(int i=0;i<q;i++)
	{
		cin>>j1;
		cin>>j2;
		if(j1.size()!=j2.size()){cout<<0<<"\n";continue;}
		else
		{
			int ans=0;
			for(int j=0;j<j1.size();j++)
			{
				if(j1[j]=='b') d1=j;
				if(j2[j]=='b') d2=j;
			}
			c2=d2-d1;
			d2=j1.size()-d2-1;
			for(int j=0;j<n;j++)
			{
				if(c1[j]==c2&&a1[j]<=d1&&a2[j]<=d2) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
