#include<bits/stdc++.h>
using namespace std;
int n,m,a[600],c[600],f[510],ans=0,mod=998244353;
string s;
void make()
{
	int cnt=0,sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
//		cout<<sum<<" "<<c[f[i]]<<endl;
		if(s[i-1]=='1'&&c[f[i]]>sum)
		{
			cnt++;
		}
		else
		{
			sum++;
		}
	}
//	cout<<cnt<<endl;
	if(cnt>=m)
	{
		ans++;
		ans%=mod;
	}
}
void dfs(int x)
{
	if(x==n)
	{
		make();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=x+1;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=s[i-1]-'0'+a[i-1];
	}
	if(m==n)
	{
		int k=0;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]<c[i]&&s[i-1]=='1');
			else
			{
				k=1;
			}
		}
		if(k==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		return 0;
	}
	if(n<=10)
	{
		dfs(0);
		cout<<ans;
	}
	return 0;
}

