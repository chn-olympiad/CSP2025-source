#include <bits/stdc++.h> 

using namespace std;
int m,n,k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		int a,b,c;
		cin>>a,b,c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}
