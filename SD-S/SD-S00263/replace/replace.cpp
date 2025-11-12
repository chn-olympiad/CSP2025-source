#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+9;
int n,q,sum[N],ans;
string sa[N],sb[N],ta,tb;
bool fg;
int gt(const string &a,const string &b)
{
	int x=0,y=0;
	for(int j=0;j<(int)a.size();j++)
	{
		if(a[j]=='b')x=j;
		if(b[j]=='b')y=j;
	}
	return x-y;
}
bool ck(int i)
{
	for(int j=0;j<(int)sa[i].size();j++)
	{
		if(sa[i][j]!='a'&&sa[i][j]!='b')return 0;
	}
	for(int j=0;j<(int)sb[i].size();j++)
	{
		if(sb[i][j]!='a'&&sb[i][j]!='b')return 0;
	}
	return 1;
}
bool check(int i,int l)
{
	for(int j=0;j<(int)sa[i].size();j++)
	{
		if(sa[i][j]!=ta[l+j]||sb[i][j]!=tb[l+j])return 0;
	}
	for(int j=0;j<l;j++)
	{
		if(ta[j]!=tb[j])return 0;
	}
	for(int j=l+(int)sa[i].size();j<(int)ta.size();j++)
	{
		if(ta[j]!=tb[j])return 0;
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i]>>sb[i];
		fg&=ck(i);
	}
	if(fg)
	{
		for(int i=1;i<=n;i++)
		{
			sum[i]=gt(sa[i],sb[i]);
		}
	}
	while(q--)
	{
		ans=0;
		cin>>ta>>tb;
		if(fg)
		{
			int x=gt(ta,tb);
			for(int i=1;i<=n;i++)
			{
				if(sum[i]==x&&sa[i].size()<=ta.size())ans++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=(int)ta.size()-(int)sa[i].size();j++)
				{
					if(check(i,j))ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*



*/
