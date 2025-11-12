#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct s{
	int u;
	int v;
	int w;
};
s arr[100001];
vector<int> v[10];

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
		int a=0;
		cin>>a;
		v[i].push_back(a);
		int b=0;
		for(int j=0;j<n;j++)
		{
			cin>>b;
			v[i].push_back(b);
		}
	}
	
	return 0;
}
/**

**/
