#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1],ri;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<n*m;j++)
		{
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r) ri=i;
	}
	int l,h;
	if(ri%n==0) l=ri/n;
	else l=ri/n+1;
	if(l%2==1) h=ri-(l-1)*n;
	else h=n+1-(ri-(l-1)*n);
	cout<<l<<' '<<h;
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
