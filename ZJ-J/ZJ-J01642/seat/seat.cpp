#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],x,y,n,m,val,p=1,id;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j) cin>>a[(i-1)*n+j];
	val=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;--i)
	if(a[i]!=val) id++;
	else break;
	x=1,y=1;
	while(id--)
	{
		int ny=y+p;
		if(ny<1||ny>n)
		{
			x++;
			p=-p;
			continue;
		}
		y=ny;
	}
	cout<<x<<" "<<y;
	return 0;
}
