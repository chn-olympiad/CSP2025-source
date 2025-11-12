//雷博尧  SN-S00759  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k;
int sum=0;
int u[N],v[N],w[N],c[N],a[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		sum += w[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>c[i];
		for(int j = 1;j<=n;j++) cin>>a[i]; 
	}
	cout<<sum<<'\n';
 } 
