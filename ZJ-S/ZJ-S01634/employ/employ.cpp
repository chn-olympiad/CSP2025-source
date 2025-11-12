#include<bits/stdc++.h>
using namespace std;
int m,n,c[505],ans=1,p,a[505],sum=0,w=0;
bool b[505];
string s;
void dfs(int d)
{
	if(d>n)
	{
		w=0;
		sum=0;
		for(int i=1;i<=s.size();i++)
		{
			if(sum>=c[a[i]])
			{
				sum++;
				continue;
			}
			if(s[a[i]]==0)
			{
				sum++;
			}
			else
			{
				w++;
			}
		}
		if(w>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==false)
		{
			a[i]=i;
			b[i]=true;
		}
		else
		{
			continue;
		}
		dfs(d+1);
		b[i]=false;
	}
	return;
}
int main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	p=n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			p--;
		}
	}
	if(n<=18)
	{
		ans=0;
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m>p)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=p;i++)
	{
		ans=ans*i;
	}
	cout<<ans;
	return 0;
}
