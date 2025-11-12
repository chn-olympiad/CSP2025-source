#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct point
{
	vector<int> dian;
	vector<int> value;
};
point tu[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int num=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,x;
		cin>>u>>v>>x;
		num+=x;
	}
	for(int i=1;i<=k;i++)
	{
		int y;
		cin>>y;
	}
	cout<<num<<endl;
	return 0;
} 
