#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[101],s[11][11];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j]=a[i*n-j+1];
			}
		}
		else 
		{
			for(int j=1;j<=n;j++)
			{
				s[i][j]=a[(i-1)*n+j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x==s[i][j])
			{
				cout<<i<<' '<<j;
				fclose(stdin);
	            fclose(stdout);
				return 0;
			}
		}
	}
}
