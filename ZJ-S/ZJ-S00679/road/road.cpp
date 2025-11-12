#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		sum+=z; 
	}
	cout<<sum; 
	return 0;
 } 
