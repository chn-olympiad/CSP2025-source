#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[10010],k=0;
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i!=0;i--)
	{
		if(a[i]==k)
		{
			k=(n*m+1)-i;
		}
	}
	if(k<=n)
	{
		cout<<1<<" "<<k<<endl;;
	}
	
	int t=1;
	for(int i=1;i<=m;i++)
	{
		if(k>n)
		{
			k=k-n;
			t++;
		}
		if(t%2==0&&k<n)
		{
			cout<<t<<" "<<n+1-k;
			break;
		}
		if(t%2!=0&&k<n)
		{
			cout<<t<<" "<<k;
			break;
		}
	}
	return 0;
}
