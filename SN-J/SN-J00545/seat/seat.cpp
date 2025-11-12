//SN-J00545  李梓源  渭南清源初级中学 
#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int ans=b[1];
	sort(b+1,b+1+n*m);
	int x=1,y=1,k=i-1;
	while(k>=1)
	{
		a[x][y]=b[k];
		k-=1;
		if(y%2==1)
		{
			if(x==n&&y==m)
			{
				break;
			}
			else if(x==n)
			{
				y++;
			}
			else
			{
				x++;
			}
			
		}
		else if(y%2==0)
		{
			if(x==1&&y==m)
			{
				break;
			}
			else if(x==1)
			{
				y++;
			}
			else
			{
				x--;
			}
			
		}
	}
	for(int ii=1;ii<=n;ii++)
	{
		for(int jj=1;jj<=m;jj++)
		{
			if(a[ii][jj]==ans)
			{
				cout<<jj<<" "<<ii;
				break;
			}
		}
	}
	return 0;
}
