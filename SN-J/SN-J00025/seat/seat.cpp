//SN-J00025 付黄旗正 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int f[15][15],a[105],n,m,ar,cot=1;
bool cmp(int a,int b)
{
	if(a>b)
	return 1;
	else
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			ar=a[i];
		}
	}
	sort(a+1,a+m*n+1,cmp);
	
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=a[cot];
				cot++;
				if(f[i][j]==ar)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				f[i][j]=a[cot];
				cot++;
				if(f[i][j]==ar)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
