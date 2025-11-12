#include <bits/stdc++.h>
using namespace std;
int n,m,rk=1,r,c,tmp;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]>a[1])
			++rk;
	}
	c=((rk-1)/n)+1;
	tmp=rk%n;
	if(!tmp)
		tmp=n;
	if(c%2)
		r=tmp;
	else
		r=n-tmp+1;
	cout<<c<<' '<<r;
	return 0;
}
