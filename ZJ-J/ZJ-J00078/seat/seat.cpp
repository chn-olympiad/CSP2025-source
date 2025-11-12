#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool s[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[(i-1)*m+j]);
			s[a[(i-1)*m+j]]=1;
		}
	}
	int k=a[1];
	int x=0;
	for(int i=100;i>=k;i--)
	{
		if(s[i]) x++;
	}
	int a=x/(2*n);
	int b=x%(2*n);
	if(b>n) a=a*2+2,b=2*n-b+1;
	else a=a*2+1;
	cout<<a<<' '<<b;
	return 0;
}