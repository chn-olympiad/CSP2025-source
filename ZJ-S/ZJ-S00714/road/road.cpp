#include<iostream>
using namespace std;
int n,m,k;
int c[20],cost[20][10001];
struct Line
{
	int u;
	int v;
	int w;	
}L[1000005];
bool Lock[1000005];
void DiJieStra()
{
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		cin >> L[i].u >> L[i].v >> L[i].w;
	}
	for(int i = 0; i < k; i++)
	{
		cin >> c[i];
		for(int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
			if(c[i] == 0)
			{
				L[j].w = 0;
			}
		}
	}
	return 0;
}
