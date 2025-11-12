#include<bits/stdc++.h>
using namespace std;

int t,n;
int v[100007][5];
int m0[100007];
int m1[100007];
int m2[100007];

int m0f[100007];
int m1f[100007];
int m2f[100007];
vector<map<int,int> > vm;
int m0s=0,m1s=0,m2s=0;
//void dfs()
//{
//	if()
//	{
//		;
//	}
//	
//}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int x=0,flagx=0,sum=0,pdA=0;
	for(int e=0;e<t;e++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
		x=0;
		for(int j=0;j<3;j++)
		{
			cin>>v[i][j];
			if(v[i][j]==0) pdA++;
			if(v[i][j]>x)
			{
				x=v[i][j];
				flagx=j;
			}
		}
		if(flagx==0)
		{
//			cout<<6<<endl;
			m0[m0s]=x;
			m0f[m0s]=i;
			m0s++;
		}
		else if(flagx==1)
		{
//			cout<<1<<endl;
			m1[m1s]=x;
			m1f[m1s]=i;
			m1s++;
		}
		else
		{
//			cout<<22<<endl;
			m2[m2s]=x;
			m2f[m2s]=i;
			m2s++;
		}
		sum+=x;
		}
		if(pdA==n*2)
		{
			sort(m0,m0+n);
			sum=0;
			for(int i=n-1;i>=n/2;i--) sum+=m0[i];
			cout<<sum;
			return 0;
		}
		int pdsize=n/2;
		if(m0s<=pdsize && m1s<=pdsize && m2s<=pdsize)
		{
			cout<<sum<<'\n';
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<v[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}
