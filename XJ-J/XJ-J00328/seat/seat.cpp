#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int x[100000][100000];
int b;
int main()    
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+1);
	while(1)
	{
		for(int i=1;i<=m;i++)
		{
				x[n][m]=a[i];
		}
	}
	return 0;
}
