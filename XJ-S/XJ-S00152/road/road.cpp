#include<bits/stdc++.h>
using namespace std;
int a[1000004],b[1000005],hs[1000005],flag[1000004];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(i=1;i<=m;i=2)
	{
		int ans=0;
		cin>>a[i]>>b[i]>>hs[i];
		if(flag[a[i]]==0 || flag[b[i]]==0)
		{
			flag[a[i]]=1;
			flag[b[i]]=1;
			ans+=hs[i];
		}
	} 
	cout<<ans;
	return 0;
} 
