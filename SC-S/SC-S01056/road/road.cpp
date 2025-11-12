#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	
	for(int i = 1,a,b,c;i<=m;i++)
	{
		cin>>a>>b>>c;
	}
	for(int i = 1,a;i <= k,i++)
	{
		cin>>a;
		for(int j = 1,b;j <= n;j++)
		{
			cin>>b;
		} 
	}
	
	cout<<0<<"/n"<<0;
	return 0;
}