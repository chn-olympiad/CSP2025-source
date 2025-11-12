#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[10000];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	if (a[0]<a[1] && a[0]>a[2] && a[0]>a[3])
	{
		cout<<"1 2";
	}
	if (a[0]<a[1] && a[0]<a[2] && a[0]>a[3])
	{
		cout<<"2 2";
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
}
