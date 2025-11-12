#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[12][12],n,m,sc[105],R,P;
	cin>>n>>m;
	P=n*m;
	for(int i=1;i<=P;i++)
	{
		cin>>sc[i];
		R=sc[1];
	}
	sort(sc+1,sc+1+P,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=n;j>=1;j--)
			{
				a[i][j]=sc[(i-1)*m+j];
				if(a[i][j]==R)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		if(i%2==0)
			for(int j=1;j<=n;j++)
			{
				a[i][j]=sc[(i-1)*m+(m-j+1)];
				if(a[i][j]==R)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
	}
	return 0;
}
