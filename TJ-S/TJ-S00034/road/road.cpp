#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005],b[1000005],c[1000005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(c+1,c+m+1);
	for(int i = 1;i < n;i++)
	{
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}
