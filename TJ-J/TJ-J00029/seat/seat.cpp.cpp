#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	cin>>a[1];
	int my=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int j=0;
	for(int i=n*m;i>=1;i--)
	{
		j++;
		if(a[i]==my)
		{
			cout<<j/m+1;
			cout<<" ";
			cout<<j%n;
			break;
		}
	}
	return 0;
}
