#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int check(int x,int y)
{
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int last=a[1],now; 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==last) now=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a[now])
		{
			cout<<check(i,m)<<" ";
			break;
		} 
	}
	if(check(now,m)!=check(now-1,m))
	{
		if(check(now-1,m)%2==0) cout<<1;
		else cout<<n;
	}
	else
	{
		if(now%n==0) cout<<n;
		else cout<<now%n;
	}
	return 0;
}
