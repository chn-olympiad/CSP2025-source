#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
int n,m,a[N];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr)
		{
			cnt=i;
			break;
		}
	}
	int lie=(cnt-1)/n+1;
	int hang=lie*n-cnt;
	if(lie%2==1)cout<<lie<<" "<<n-hang;
	else cout<<lie<<" "<<hang+1;
	return 0;
}
