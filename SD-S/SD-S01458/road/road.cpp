#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,c[15][N],ww[15],sum=0;
struct node{int to,len;};
vector<node>a[N];
void work1()
{
	
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		sum+=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>ww[i];
		for(int j=1;j<=n;j++)
		cin>>c[i][j];
	}
	if(k==0) {
		work1();
		return 0;
	}
	
	
	return 0;
 } 
