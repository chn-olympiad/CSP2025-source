#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m,a[N],r,p;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			p=i;
			break;
		}
	}
	int c=ceil(p*1.0/n);
	cout<<c<<" ";
	if(c&1)
	{
		if(p%n!=0)
			cout<<p%n;
		else
			cout<<n;
	}
	else
	{
		if(p%n!=0)
			cout<<n-(p%n)+1;
		else
			cout<<1;
	}
	return 0;
}

