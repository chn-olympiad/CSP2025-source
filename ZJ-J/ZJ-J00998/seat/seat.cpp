#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
int n,m,a1,k=1;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a1;
	f(i,2,n*m)
	{
		int x;
		cin>>x;
		if(x>a1)k++;
	}
	if(k%n==0)cout<<k/n<<' '<<(k/n%2==0?1:n);
	else cout<<k/n+1<<' '<<((k/n+1)%2==0?(n-(k%n)+1):(k%n));
	return 0;
}
