#include <bits/stdc++.h>
using namespace std;
struct node
{
	int id,sy;
};
node a[110];
bool cmp(node x,node y)
{
	return x.sy>y.sy;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,we;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i].sy,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i].id==1) 
		{
			we=i;
			break;
		}
	int h,l;
	if (we%n==0) cout<<we/n<<" "<<n;
	else
	{
		h=we/n+1;
		l=we%n;
		if (h%2==1) cout<<h<<" "<<l;
		else cout<<h<<" "<<n-l+1;
	}
	return 0;
}
