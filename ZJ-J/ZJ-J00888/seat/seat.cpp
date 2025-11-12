#include<bits/stdc++.h>
using namespace std;
int a[105],w[105][105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2!=0)
				w[i][j]=a[(i-1)*n+j];
			else
				w[i][j]=a[n*i-j+1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(w[i][j]==r)
			{
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	cout<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
