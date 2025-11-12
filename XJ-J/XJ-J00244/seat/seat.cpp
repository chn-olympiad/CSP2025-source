#include<bits/stdc++.h>
using namespace std;
long long int a[1001],i,j,ans,k,n,m,w;
string s;
int main()
{		freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
for(i=1;i<=n*m;i++)
cin>>a[i];
w=a[1];
sort(a+1,a+1+n*m);
for(i=n*m;i>=1;i--)
{
	j++;
if(a[i]==w){k=j;break;}
}
for(i=1;i<=m;i++)
{
	if(i%2==1)
	for(j=1;j<=n;j++)
	{
		k--;
		if(k==0)
		{cout<<i<<" "<<j;return 0;}
	}
	else
	for(j=n;j>=1;j--)
	{
		k--;
		if(k==0)
		{cout<<i<<" "<<j;return 0;}   
	}
}
return 0;
}

