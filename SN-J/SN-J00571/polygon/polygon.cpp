#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	
	return 0;
}
