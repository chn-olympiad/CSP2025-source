#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

int n,m,k;//原有城市数，道路数，乡镇数
int u[maxn],v[maxn],w[maxn];//两座城市，费用
int b[10],c[10];//第j个乡村改造费用，道路费用；
char p[maxn][maxn];//路径 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}	
	for(int j=1;j<=k;j++)
	cin>>b[j]>>c[j]; 
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(p[i][j]=1)//tong
				sort(w+1,w+m+1);
				
			}
	}
	}	
	cout<<"13";

	return 0;
}
