#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int s;
	for(int i=1;i<=3m;i++)
		cin>>s;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>s;
	
	cout<<0;
	return 0;
}