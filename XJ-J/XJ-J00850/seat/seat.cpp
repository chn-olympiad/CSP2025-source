#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b[105],j=1,r,u,a1,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		b[j]=a[i];
		if(b[j]==a1)
		c=j;
		j++;
	}
	for(int i=1;i<=m;i++)
	if(i%2==1)
	for(j=1;j<=n;j++)
	{
		c--;
		if(c==0)
		cout<<i<<" "<<j;
	} 
	else
	for(j=n;j>=1;j--)
	{
		c--;
		if(c==0)
		cout<<i<<" "<<j;
	} 
	return 0;
}
