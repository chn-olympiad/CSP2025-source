#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],r=1,mmx[105][105],s;
bool b(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,b);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				mmx[j][i]=a[r];
				r++;
				if(mmx[i][j]==s)
				{
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				mmx[j][i]=a[r];
				r++;
				if(mmx[i][j]==s)
				{
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
//2 2
//98 99 100 97