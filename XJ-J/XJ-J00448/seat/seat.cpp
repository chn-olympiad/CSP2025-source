#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int cmp(int x,int y)
{
	if(x>=y) return x;
	else return y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for (int j=m;j>=1;j++)
			{
				if(a[(i-1)*m+j]==k) 
				{
					if(m%2==0&&j>m/2)
					{
						cout <<j-(j-(m/2))*2+1<<" "<<i;
					}
					if(m%2==0&&j<m/2)
					{
						cout<<j+(m/2-j)*2+1<<" "<<i;
					}
					if(m%2!=0&&j>m/2)
					{
						cout<<j-(j-(m/2))*2<<" "<<i;
					}
					if(m%2!=0&&j<m/2)
					{
						cout<<j+(m/2-j)*2<<" "<<i;
					}
				}
			}
		}
		else
		{
			for (int j=1;j<=m;j++)
			{
				if(a[(i-1)*m+j]==k) cout <<j<<i;
			}
		}
	}	
	return 0;
}
