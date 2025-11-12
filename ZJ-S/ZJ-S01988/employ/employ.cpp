#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int ,vector<int>,greater>
//#define pql priority_queue<int ,vector<int> >
using namespace std;
int n,m;
string dy;
int a[1000],vis[1000];
int f(int x,int s)
{
	if(x==n+1)
	{
		if(n-s>=m)return 1;
		else return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		vis[i]=1;
		if(s>=a[i]||dy[x-1]=='0')sum+=f(x+1,s+1);
		else 
		{
			sum+=f(x+1,s);
		}
		vis[i]=0;
	}
	return sum;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>dy;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<f(1,0);
	return 0;
}
