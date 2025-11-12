#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
	}
	cout<<sum/2-1;
	return 0;
}
