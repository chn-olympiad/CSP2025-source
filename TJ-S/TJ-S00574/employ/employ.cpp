#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#define ll long long
using namespace std;
int n,m; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	char a;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='0'&&n==m)
		{
			cout<<0;
			return 0;
		}
	}
	int b;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		
		if(b==0)
		{
			cout<<0;
			return 0;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
	}
	cout<<ans;
	return 0;
 }

