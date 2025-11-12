#include <bits/stdc++.h>
using namespace std;
int n,m,re,pos,a[110];
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	re=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==re)pos=i;
	}
	int x=(pos-1)/n+1,y=(pos-1)%n+1;
	if(x%2==1)cout<<x<<" "<<y;
	else cout<<x<<" "<<n+1-y;
	return 0;
}