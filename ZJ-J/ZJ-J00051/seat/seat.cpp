#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int id;
struct node
{
	int x,id;
}a[N];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			id=i;
		}
	}
	if((id+n-1)/n%2)
	{
		if(id%n==0)
		{
			cout<<(id+n-1)/n<<" "<<n;
		}
		else
		{
			cout<<(id+n-1)/n<<" "<<id%n;
		}
	}
	else
	{
		cout<<(id+n-1)/n<<" "<<n-id%n;
	}
}
