#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);	
	int n;
	cin>>n;
	int a[n+5];
	int sum=1;
	while(n!=1)
	{
		a[sum]=n%2;
		n/=2;
	}
	cout<<n;
	for(int i=sum;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
