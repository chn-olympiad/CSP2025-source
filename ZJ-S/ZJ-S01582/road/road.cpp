#include<bits/stdc++.h>
#define int long long 
using namespace std;

struct rode{
	int a,b,price;
}e[1000005];
int a[1000005],idx;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,idx=m,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].a>>e[i].b>>e[i].price;
		sum+=e[i].price;
	}
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		for(int j=1;j<=n;j++)
		{
			int b;
			cin>>b;
		}
	}
	cout<<sum;
	return 0;
}
