#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[105],b[15][15],x;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k=0;
	cin >> n >> m;
	for (i=1; i<=n*m; i++)
		cin >> a[i];
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for (i=1; i<=m; i++)
		if (i%2==1)
			for (j=1; j<=n; j++)
				b[i][j]=a[++k];
		else
			for (j=n; j>=1; j--)
				b[i][j]=a[++k];
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (b[i][j]==x)
				cout << i << " " << j;
	return 0;
}
