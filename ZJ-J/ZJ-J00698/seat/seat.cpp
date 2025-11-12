#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
struct node{
	int x,id;
}a[N];
int n,m,l,h,x;
bool cmp(node x,node y)
{
	return x.x>y.x;
}
signed main()
{
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			x=i;
			break;
		}
	}
	l=(x+n-1)/n;
	if(l%2==0)
		h=l*n-x+1;
	else
		h=x-l*n+n;
	cout<<l<<" "<<h;
 	return 0;
}
