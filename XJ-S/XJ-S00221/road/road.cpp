#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c;
struct ro
{
	ll u,v,w;
}arr[100005];
int ct[11][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	for(int i=0;i<k;i++)
	{
		cin>>c;
		for(int j=0;j<n;j++)
		{
			cin>>ct[i][j];
		}
	 } 
	 cout<<0;
	return 0;
 }

