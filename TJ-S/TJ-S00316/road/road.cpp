#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	int t,n,m,k,s,u[1000000000],v[10000000000],w[100000000],a[1000000010],c[1000000000];
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];	
	}
	
	for(int j=1;j<=k;j++)
	{
		cin >> c[j];
		for(int i=1;i<=n+1;i++)
		{
			cin >> a[i];
		}
	}
	cout << s;
	
	return 0;
}










