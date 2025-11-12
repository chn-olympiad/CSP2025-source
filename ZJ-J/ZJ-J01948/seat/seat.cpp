#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,x,a[150];
int main()
{
	Fcin;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	int p=0;
	for(int i=n*m;i>=1;--i)
	{
		p++;
		if(a[i]==x) break;
	}
	int t=(p+n-1)/n;
	cout<<t<<" "<<((t&1)?p-n*(t-1):n*t+1-p);
	return 0;
}

