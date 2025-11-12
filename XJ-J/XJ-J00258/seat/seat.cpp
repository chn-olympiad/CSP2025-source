#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	int s=n*m;
	for(int i=0;i<s;i++)
		cin >> a[i];
	int x=a[0];
	sort(a,a+s,greater<int>());
	for(int i=0;i<s;i++)
	{
		if(a[i]==x)
		{
			x=i+1;
			break;
		}
	}
	cout<<ceil(x*1.0/n)<<' ';
	if(x%n==0)
		cout<<x;
	else if((int)(ceil(x*1.0/n))%2==1)
		cout<<x%n;
	else
		cout<<n+1-x%n;
	return 0;
}
