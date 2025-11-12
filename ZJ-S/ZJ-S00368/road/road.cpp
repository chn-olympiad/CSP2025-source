#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	long long n,m,min_p = 1000000;
	int k;
	cin>>n>>m>>k;
	int city[10000][10000] = {0},am = 0, bm = 0;
	for(int i = 0;i<m;i++)
	{
		int a,b,p;
		cin>>a>>b>>p;
		if(p<min_p)
		{
			min_p = p;
			am = a;
			bm = b;
		}
		city[a][b] = p;
		city[b][a] = p;
	}
	
	return 0;
}
