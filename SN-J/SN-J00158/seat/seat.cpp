/*
	SN-J00158 
	华紫陌
	西安辅轮中学 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[101];
int x(int k)
{
	return k/n+1;
}
int y(int k)
{
	if((k/n+1)%2)
	{
		if(k%n==0) return n;
		return k%n;
	}
	else
	{
		if(n+1-(k%n)==n+1) return 1;
		return n+1-(k%n);
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1);
	int c;
	for(int i=1;i<=n*m;i++)
		if(a[i]==R) c=i;
	cout<<x(n*m+1-c)<<" "<<y(n*m+1-c);
	return 0;
}
