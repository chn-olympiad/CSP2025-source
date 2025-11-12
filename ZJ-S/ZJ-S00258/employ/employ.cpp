#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,a[505],x,mod=998244353,ss;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int xx=1,yy=0,zz=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)
			{
				xx*=++yy;
				xx%=mod;
			}
			zz*=i;
			zz%=mod;
		}
	for(int i=0;i<yy;i++)
	{
		x+=s[i]-48;
	}
	if(x<m)
	{
		cout<<0;
		return 0;
	}
	if(n<=10)
	{
		for(int i=1;i<=zz;i++)
		{
			bool bb=1;
			int k=0,mvp=0;
			for(int j=1;j<=n;j++)
			{
				if(k>=a[j])
				{
					k++;
					continue;
				}
				if(s[j-1]=='0')
				{
					k++;
				}
				else
				{
					mvp++;
				}
			}
			if(mvp<m)
			{
				bb=0;
			}
			ss+=bb;
			next_permutation(a+1,a+n+1);
		}
		cout<<ss;
	}
	else if(x==yy)
	{
		cout<<xx;
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
}

