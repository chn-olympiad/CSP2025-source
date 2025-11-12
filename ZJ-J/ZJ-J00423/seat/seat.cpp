#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],n,m;
int b[N*N];
bool cmp(int x,int y)
{
	return x>y;
}
int ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[(i-1)*m+j-1]=a[i][j];
		}
	}
	ans=a[1][1];
	sort(b,b+n*m,cmp);
	int top=0;
	while(1)
	{
		if(b[top]==ans)
		{
			cout<<x<<" "<<y;
			break;
		}
		if(x%2==1)
		{
			if(y!=n)
			y++;
			else
			x++;
		}
		else
		{
			if(y!=1)
			y--;
			else
			x++;
		}
		top++;
	}
	return 0;
}
