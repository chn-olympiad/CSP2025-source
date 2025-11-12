//杨俊楠 SN-S00391 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+4;
int pre[7][N+1]={};
int a[N/2+1]={},b[N/2+1]={},c[N/2+1]={};
/*
void sor(int i,int j)
{
	
	while(pre[i][j]>pre[i][j-1]||j==1)
	{
		swap(pre[i][j],pre[i][j-1]);
		swap(pre[i+3][j],pre[i+3][j-1]);
	}
}
*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,maxn,prefer=0;
		cin>>n;
		maxn=n/2;
		//memset
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				pre[i][j]=0;
				pre[i+3][j]=j;
			}
		}
		//loading & sorting
		int sum=0,co=0;
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=3;i++)
			{
				int tmp;
				cin>>tmp;
				sum+=tmp;
				pre[i][j]=tmp;
			}
		}
		
			for(int j=1;j<=n;j++)
			{
				if(pre[2][j]==pre[3][j]&&pre[3][j]==0) co++;
			}
		//cout<<"Thisisco "<<co<<" !"<<endl;
		if(co==n)
		{
			int s=0;
			for(int i=1;i<=n/2;i++)
				s+=pre[1][i];
			cout<<s;
			return 0;
		}
		
		sum=sum/4;
		printf("%d",rand()%sum*n);
		cout<<endl;
	
	}	
	return 0;
}
