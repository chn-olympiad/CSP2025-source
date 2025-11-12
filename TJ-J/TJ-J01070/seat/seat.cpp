#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main()
{
	cin>>n>>m;
	cin>>a[1];
	int num=a[1],ans=0;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==num)
		{
			ans=i;
			break;
		}
	}
	cout<<(n*m)/ans<<" "<<(n*m)%ans;
	return 0;
}
