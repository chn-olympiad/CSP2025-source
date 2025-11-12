#include<bits/stdc++.h>
using namespace std;
long long a[5005],flag[220][20],t[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,i,j,k,x=0,y=0,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		x=x+a[i];
	 } 
	sort(a+1,a+n+1);
	if(x>a[n])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
