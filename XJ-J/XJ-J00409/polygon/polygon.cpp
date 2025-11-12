#include<bits/stdc++.h>
using namespace std;
long long int a[10006],n;
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1&&n==2)
	{
		cout<<0;
		return 0;
	}
	else
	for(int i=1;i<=n;i++)
	{
		if(a[i]+a[i+1]>a[i+2]&&a[i]+a[i+2]>a[i+1]&&a[i+1]+a[i+2]>a[i])
		cout<<1<<endl;
		return 0;
	}
	return 0;
}
