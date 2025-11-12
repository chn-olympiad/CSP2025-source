#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	int a[l];
	for(int i=1;i<=l;i++)
	{
		cin>>a[i];
	}
	if(a[1]<a[l]&&a[1]<a[l-1]&&a[1]<a[l-2]&&a[1]<a[l-3])
	{
		cout<<n<<m;
	}
	else if(a[1]<a[l]&&a[1]<a[l-1]&&a[1]<a[l-2]&&a[1]>a[l-3])
	{
		cout<<n<<m-1;
	}
	else if(a[1]<a[l]&&a[1]<a[l-1]&&a[1]>=a[l-2]&&a[1]>=a[l-3])
	{
		if(m-2!=0) cout<<n<<m-2;
		else cout<<n-1<<m;
	}
	else if(a[1]<a[l]&&a[1]>=a[l-1]&&a[1]>=a[l-2]&&a[1]>=a[l-3])
	{
		if(m-3!=0) cout<<n<<m-3;
		else cout<<n-1<<m-1;
	}
	return 0;
}