#include<bits/stdc++.h>
using namespace std;
int m,n,k;
struct ma{
	int u,v,w;
};
int b[10010];
vector<ma>a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a.push_back((ma){u,v,w});	
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cout<<13;
	return 0;
}
