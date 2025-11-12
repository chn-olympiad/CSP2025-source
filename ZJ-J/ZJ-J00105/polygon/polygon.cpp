#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],b=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+3+1);
	for(int i=1;i<=3;i++)
	{
		b+=a[i];
	}
	if(b>2*a[3])
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
