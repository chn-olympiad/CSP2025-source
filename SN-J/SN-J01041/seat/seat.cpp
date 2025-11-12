#include<bits/stdc++.h>
using namespace std;

long long a[5050][5050];
long long b[100010];

struct node
{
	long long xue;
	
}mi[1000010];

bool cmp(node a,node b)
{
	return a.xue>b.xue;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0;
	cin>>n>>m;
	long long ans=n*m;
	for(int i=1;i<=ans;i++)
	{
		cin>>mi[i].xue;
		
	}
	long long num=mi[1].xue;
	sort(mi+1,mi+1+ans,cmp);
	for(int i=1;i<=m;i++)
	{ 
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=mi[++z].xue;
				if(a[i][j]==num)
				{
					cout<<i<<" "<<j;
				}
			}
			
		}
		else if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=mi[++z].xue;
				//cin>>a[i][j];
				//cout<<a[i][j]<<i<<" "<<j<<" ";
				if(a[i][j]==num)
					cout<<i<<" "<<j<<" ";
			}
		}
	
		
	 } 
	
	return 0;
 } 
 
 /* 
2 2
98 100 99 97

3 3
94 95 96 97 98 99 100 93 92
 */
