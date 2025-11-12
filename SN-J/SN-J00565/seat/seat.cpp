#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[(n*m)];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int v=a[0];
	sort(a,a+(n*m),cmp);
	int k;
	for(int i=0;i<n*m;i++) if(v==a[i]) k=i+1;
	int c,r;
	c=k/n;
	if(c%2==0) r=k%n;
	if(c%2)
	{
		r=k%n;
		r=n+1-r;
	}
	if(r==0||r==n+1)
	{
		if(r==0) r=1;
		else r=n;
		cout<<c<<' '<<r;
	}
	else cout<<c+1<<' '<<r;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
