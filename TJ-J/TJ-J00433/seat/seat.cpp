#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 500
int a[N],se[11][11];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,RP=0;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		{
			if(i==1)
				{
					cin>>a[i];
					RP=a[i];
					continue;
				}
			cin>>a[i];
		}
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int j=1; j<=m; j++)
		{
			if(j%2!=0)
				{
					for(int i=1; i<=n; i++)
						{
							se[i][j]=a[k];
							k++;
						}
				}
			else if(j%2==0)
				{
					for(int i=n; i>=1; i--)
						{
							se[i][j]=a[k];
							k++;
						}
				}
		}
	for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
				{
					if(se[i][j]==RP)
						{
							cout<<j<<" "<<i;
							return 0;
						}
				}
		}
	return 0;
}
