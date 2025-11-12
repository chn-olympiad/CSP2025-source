#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin >> n >> m >> k ;
	int a1,a2,a3;
	for(int i=1;i<=n;i++)
	{
		cin >> a1 >> a2 >> a3;
		ans+=a3;
	}
	cout << sqrt(2*ans);
	return 0;
}
