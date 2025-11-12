#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200;
const int M=998244353;
int n,m,sum;
int a[N],c[N],p[N];
bool vis[N];
string s;
void check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[a[i]])
			cnt++;
		else if(!vis[i])
			cnt++;	
	}
	if(n-cnt>=m)
		sum++;
}
void dfs(int x)
{
	if(x>n)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);	
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	bool flag=1;
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*i%M;
		if(s[i]!='1')
			flag=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=18)
	{
		dfs(1);
		cout<<sum<<endl;
	}
	else if(m==n)
	{
		if(!flag)
			cout<<0;
		else
			cout<<p[n];
	}
	else if(flag)
		cout<<p[n];
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	return 0;
}
