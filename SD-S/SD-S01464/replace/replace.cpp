#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=6e6+10;
int tr1[N][30];
int tr2[N][30];
int cnt1=0,cnt2=0;
int st1[M],st2[M];
void insert1(string s,int pos)
{
	int p=0;
	for(int i=0;i<(int)s.size();i++)
	{
		int c=s[i]-'a';
		if(!tr1[p][c])
		{
			tr1[p][c]=++cnt1;
		}
		p=tr1[p][c];
	}
	st1[p]=pos;
}
void insert2(string s,int pos)
{
	int p=0;
	for(int i=0;i<(int)s.size();i++)
	{
		int c=s[i]-'a';
		if(!tr2[p][c])
		{
			tr2[p][c]=++cnt2;
		}
		p=tr2[p][c];
	}
	st2[p]=pos;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		insert1(s1,i);
		insert2(s2,i); 
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("0\n");
			continue;
		}
		int st=0,en=0; 
		int n=t1.size();
		for(int i=0;i<n;i++)
		{
			if(t1[i]!=t2[i])
			{
				en=i;
			}
		}
		for(int i=n-1;~i;i--)
		{
			if(t1[i]!=t2[i])
			{
				st=i;
			}
		}
		int ans=0;
		for(int i=0;i<=st;i++)
		{
			int p1=0,p2=0;
			for(int j=i;j<n;j++)
			{
				int c1=t1[j]-'a';
				int c2=t2[j]-'a';
				if(!tr1[p1][c1]||!tr2[p2][c2])
				{
					break;
				}
				p1=tr1[p1][c1];
				p2=tr2[p2][c2];
				if(st1[p1]==st2[p2]&&st1[p1]&&j>=en)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

