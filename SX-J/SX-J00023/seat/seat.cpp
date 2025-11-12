#include<bits/stdc++.h>
using namespace std;
int n,m;
int pepole[10000];
int room[200][200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++)
	{
		cin>>pepole[i];
	}
	r=pepole[0];
	for(long long i=0;i<n*m;i++)
	{
		for(long long j=i;j<m*n;j++)
		{
			if(pepole[i]<pepole[j])
			{
				int t;
				t=pepole[i];
				pepole[i]=pepole[j];
				pepole[j]=t;
			}
		}
	}
	int y;
	int x;
	int xb=0;
	for(int i=1;i<=n;i++)
 	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				room[i][j]=pepole[xb];
				xb++;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				room[i][j]=pepole[xb];
				xb++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(room[i][j]==r)
			{
				x=i;y=j;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}