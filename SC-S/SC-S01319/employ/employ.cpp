#include<bits/stdc++.h>
using namespace std;
int n,m,num;
string a;
int s[600],q[600];
void check()
{
	int out=0,in=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]=='0'||s[q[i]]<=out)
		{
			out++;
		}
		else
		{
			in++;
		}
	}
	if(in>=m)
	{
		num++;
		
		return;
	}
	return;
}
void dfs(int step)
{
	if(step>n)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(q[i]==0)
		{
			q[i]=step;
			dfs(step+1);
			q[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	dfs(1);
	cout<<num<<endl;
	return 0;
}