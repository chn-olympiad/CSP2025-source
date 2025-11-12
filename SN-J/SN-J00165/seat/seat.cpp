#include<bits/stdc++.h>
using namespace std;

int n, m, a[105];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i<n*m; i++)
	{
		cin>>a[i];
	}
	int temp=a[0];
	sort(a, a+n*m, cmp);
//	for(int i = 0;  i<n*m; i++) cout<<a[i]<<' ';
	int i = 0;
	while(a[i]!=temp)
	{
		i++;
	}
	i++;
//	cout<<a[i-1]<<endl;
	int l=((i-1)/n+1);
	if(l%2==1)
	{
		if(i%n==0) cout<<l<<' '<<n;
		else cout<<l<<' '<<i%n;
	}
	else 
	{
		if(i%n==0) cout<<l<<' '<<1;
		else cout<<l<<' '<<n-i%n+1;
	}
	return 0;
}
