#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	long long n,max,cnt=0;
	cin>>n;
	int length[n+5];
	for (int i=0;i<n;i++)
	{
		cin>>length[i];
		cnt+=length[i];
	}
	sort(length,length+n);
	if (n<3)
	{
		cout<<0;
		exit(0);
	}
	if (cnt>2*length[n-1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
