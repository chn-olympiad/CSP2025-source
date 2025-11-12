#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,x,y,p[1001][1001];
struct node
{
	ll n,i;
}a[1001];
bool cmp(node x,node y)
{
	return(x.n>y.n);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i].n;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i].i==1)break;
	}
	x=i%n;
	if(x==0)x=n;
	y=(i-1)/n+1;
	if(y%2==0)x=n-x+1;
	cout<<y<<" "<<x<<"\n";
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
