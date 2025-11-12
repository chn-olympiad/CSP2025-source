#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
mt19937 rnd(time(0));
const int mod=1e9+1;
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n=10000,m=1000000,k=10;
	cout<<n<<' '<<m<<' '<<k<<'\n';
	F(i,2,n)
	{
		cout<<i<<' '<<rnd()%(i-1)+1<<' '<<rnd()%mod<<'\n';
	}
	F(i,1,m-n+1)cout<<rnd()%n+1<<' '<<rnd()%n+1<<' '<<rnd()%mod<<'\n';
	F(i,1,k)
	{
		cout<<rnd();
		F(i,1,n)cout<<" "<<rnd()%mod;
		cout<<'\n';
	}
	return 0;
}
