#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],R;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	int j=0;
	for(int i=0;a[i]!=R;i++)
	{
		j++;
	}
	j=n*m-j;
	cout<<(j-1)/n+1<<" ";
	if(j%(n*2+1)>n)
	{
		cout<<n-j%(n+1)<<" ";
	}
	else
	{
		cout<<(j-1)%n+1<<" ";
	}
	return 0;
}
