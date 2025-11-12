#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans[505];
string s;
long long x;
const int P=998244353;
void dfs(int step)
{
	if(step>n)
	{
		int l=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				if(c[ans[i]]<l)
				{
					sum++;
				}
				else
				{
					l++;
				}
			}
			else
				l++;
		}
		if(sum>=m)
			x++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i]=j;//第i天去的人是第j个
			dfs(step+1);
		}
	}
}
void tpdfs(int step)
{
	if(step>m)
	{
		x++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==ans[step-1])
			continue;
		ans[step]=i;
		tpdfs(step+1);
	}
}
int main()
{
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
			sum++;
	}
	x=1;
	sort(c+1,c+1+n);
	n-=sum;
	for(int i=1;i<=m;i++)
		x=(x*i)%P;
	cout<<x;
 	return 0;
}