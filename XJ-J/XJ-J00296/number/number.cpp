#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	if(n/10>0&&n/10<n%10)
	{
		n=n%10*10+n/10*1;
	}
	cout<<n;
	return 0;
}
