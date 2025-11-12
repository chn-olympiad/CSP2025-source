#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	if(a!=b)
		return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={},k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			k=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
			k=i;
	}
	int i=k/(2*n),j=k%(n*2);
	if(j==0)
	{
		cout<<k/n<<" "<<1;
	}
	else if(j>n)
	{
		int l=k%n;
		cout<<k/n+1<<" "<<n-l+1;
	}
	else if(j==n)
	{
		cout<<k/n<<" "<<n;
	}
	else if(j<n)
	{
		cout<<k/n+1<<" "<<j;
	}
	return 0;
}
