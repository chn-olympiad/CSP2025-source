#include<bits/stdc++.h> 
using namespace std;
int n,m,k,a[10001][10001],c[10005],a2[30][10000];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<(sizeof(a)+sizeof(a2)+sizeof(c))/1024/1024;
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++) cin>>a2[j][i];
	}
	for(int i=1;i<=n;i++)
	{
		int kk=0;
		for(int j=1;j<=k;k++)
		{
			if(i<=k)
			{
				kk=1;
				break;
			}
		}
		if(kk=0)
		{
			for(int j=1;j<=n;j++)
			{
				sum+=a[i][j];
				a[i][j]=0;
				a[j][i]=0;
			}
		}
		else{
			int fff=0;
			for(int j=1;j<=n;j++)
			{
//				cout<<a2[i][j]<<" "<<a[i][j]<<endl;
				fff=fff+min(a2[i][j],a[i][j])-a[i][j];
//				cout<<fff<<endl;
			}
				
//			cout<<fff<<endl;
			if(fff+c[i]<0)
			{
//				cout<<fff+c[i]<<endl;
				sum+=c[i];
				for(int j=1;j<=n;j++)
				{
					sum+=min(a[i][j],a2[i][j]);
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
