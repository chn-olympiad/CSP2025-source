#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,d=0;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		cin>>a>>b>>c;
		d = d+c;
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
