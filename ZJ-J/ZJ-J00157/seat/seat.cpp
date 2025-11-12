#include <bits/stdc++.h>
using namespace std;
int n,m,a[114];
int mark,od;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	mark=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==mark)
		{
			od=i;
			break;
		}
	}
	int c=(od-1)/n+1;
	int r;
	if(c%2==1)r=((od-1)%n)+1;
	else r=n-((od-1)%n);
	cout<<c<<' '<<r;
	return 0;
}
