#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[10000005],ans[10005][10005],t,g,h;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=a[++k];
				if(a[k]==t)
				{
					g=i;
					h=j;
				}
			}
		}else
		{
			for(int j=n;j>=1;j--)
			{
				ans[i][j]=a[++k];
				if(a[k]==t)
				{
					g=i;
					h=j;
				}
			}
		}
	}
	cout<<g<<" "<<h;
	return 0;
}