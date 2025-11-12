#include<bits/stdc++.h>
using namespace std;
long long m,n,k,a[100005]ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans;
	return0;
}
