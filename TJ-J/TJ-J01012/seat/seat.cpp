#include<bits/stdc++.h>
using namespace std;
int x,y,a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++) cin>>a[i];
	int l=a[1];
	sort(a+1,a+1+(x*y));
	for(int i=x*y,j=1;i>=1;i--,j++)
	{
		if(a[i]==l)
		{
			if(j%x==0) cout<<j/x<<' ';
			else cout<<(j/x)+1<<' ';
			if(j%(x*2)>x||j%(x*2)==0) cout<<((j%(x*2)%x)+1)%(x+1);
			else cout<<j%(x*2);
			cout<<'\n';
		}
	}
	return 0;
}
