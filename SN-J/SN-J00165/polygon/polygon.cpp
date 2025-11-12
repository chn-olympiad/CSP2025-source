#include<bits/stdc++.h>
using namespace std;

int n, a[5005], ans=0, fonn[5005], maxc;

int fon(int c, int d, int j)
{
	if(c==0) 
	{
		int temp=0;
		for(int i = 1; i<=maxc; i++)
		{
			temp+=a[fonn[i]];
		}
		int maxx=0;
		for(int i = 1; i<=maxc; i++)
		{
			maxx=max(maxx, a[fonn[i]]);
		}
		if(temp>maxx*2) return 1;
		else return 0;
	}
	int temp=0;
	for(int i = d+1; i<n-j; i++)
	{
		fonn[c]=i;
		temp+=fon(c-1, i, j-1);
	}
	return temp;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	bool f=0;
	for(int i = 0; i<n; i++) 
	{
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(n==3)
	{
		if(a[0]+a[1]+a[2] > 2*max(a[0], max(a[1], a[2]))) cout<<1;
		else cout<<0;
	}
	else if(!f)
	{
		int c=1, cc=2;
		for(int i = 2; i<n; i++)
		{
			ans+=c;
			c+=cc;
			cc+=1;
		}
		cout<<ans;
	}
	else 
	{
		for(int k = 3; k<n; k++)
		{
			maxc=k;
			ans+=fon(k, -1, k-1);
		}
		cout<<ans+1;
	}
	return 0;
}
