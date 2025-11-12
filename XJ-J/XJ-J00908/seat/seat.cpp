#include <bits/stdc++.h>

using namespace std;
int n,m;
int b[10010];
int lb;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			cin>>b[++lb];
		}
	}
	int x = b[1];
	sort(b+1,b+lb+1);
	int xp = -1;
	for(int i = 1;i<=lb;i++)
	{
		if(b[i]==x)
		{
			xp = lb-i+1;
			break;
		}
	}
//	cout<<xp;
	int hang,lie;
	lie = (xp-1)/n+1;
	int yu = xp%n;
	if(yu==0) yu = n;
	if(lie%2==1) hang = yu;
	else hang = m-yu+1;
	cout<<lie<<" "<<hang;
	return 0;
}
