#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			int c=i%n,r=(i-1)/n+1;
			if(c==0) c=n;
			if(r%2==0) c=n-c+1;
			cout<<r<<' '<<c;
		}
	}
	return 0;
} 
