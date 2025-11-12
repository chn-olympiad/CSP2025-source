#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,sum=1;
void f(int x,int k)
{
	if(k<=m)
	{
		if(x&1) cout<<x<<" "<<k;
		else cout<<x<<" "<<m-k+1;
		return;
	}
	else return f(x+1,k-m);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++)
	{
		cin>>y;
		if(y>x) sum++;
	}
	f(1,sum);
	return 0;
}