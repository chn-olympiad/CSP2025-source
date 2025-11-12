#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110];
bool cmp(int X,int Y)
{
	return X>Y;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int c=a[1],num;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]!=c)continue;
		num=i;
		break;
	}
	int lie=(num+n-1)/n,hang;
	if((num-1)%(2*n)+1 > n)hang=n-(num-1)%n;
	else hang=(num-1)%n+1;
	cout<<lie<<' '<<hang;
	return  0;
}
