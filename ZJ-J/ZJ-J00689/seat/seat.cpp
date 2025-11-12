#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt;
string s;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	cin>>a[1];
	for(int i=2;i<=k;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int c=cnt/n+1;
	int r=cnt%n+1;
	cout<<c<<" ";
	if(c%2==1) cout<<r;
	else cout<<n-r+1;
	return 0;
}
