#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1000050];
vector<int>e[1000050];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,f;
		cin>>a>>b>>f;
		e[a].v.push_back(b);
		e[b].push_back(a);
		w[i]=f;
	}
	
	return 0;
}
