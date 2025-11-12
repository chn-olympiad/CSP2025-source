#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,sum[5];
struct Node
{
	int d,maxi,midi,num[5]={0};
	bool operator <(const Node &oth)
	{
		return d>oth.d; 
	};
}f[N];
int maxn(int a,int b,int c)
{
	if(a>=b&&b>=c)
		return 1;
	else if(a>=c&&c>=b)
		return 1;
	else if(b>=a&&a>=c)
		return 2;
	else if(b>=c&&c>=a)
		return 2;
	else if(c>=a&&a>=b)
		return 3;
	else if(c>=b&&b>=a)
		return 3;
	return 0;
}
int mid(int a,int b,int c)
{
	if(a>=b&&b>=c)
		return 2;
	else if(a>=c&&c>=b)
		return 3;
	else if(b>=a&&a>=c)
		return 1;
	else if(b>=c&&c>=a)
		return 3;
	else if(c>=a&&a>=b)
		return 1;
	else if(c>=b&&b>=a)
		return 2;
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i].num[1]>>f[i].num[2]>>f[i].num[3];
			f[i].midi=mid(f[i].num[1],f[i].num[2],f[i].num[3]);
			f[i].maxi=maxn(f[i].num[1],f[i].num[2],f[i].num[3]);
			f[i].d=f[i].num[f[i].maxi]-f[i].num[f[i].midi];
		}
		sort(f+1,f+1+n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(sum[f[i].maxi]<(n/2))
			{
				sum[f[i].maxi]++;
				ans+=f[i].num[f[i].maxi];
			}
			else if(sum[f[i].midi]<(n/2))
			{
				sum[f[i].midi]++;
				ans+=f[i].num[f[i].midi];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
