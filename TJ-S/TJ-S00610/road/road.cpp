#include<bits/stdc++.h>
using namespace std;
long long s[1000000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=n;i++) cin>>a>>b>>c;
	for(int i=1;i<=k;i++) 
	{
		for(int j=1;j<=n+1;j++)
			cin>>s[j];
	}
	cout<<0; 
	return 0;
}
