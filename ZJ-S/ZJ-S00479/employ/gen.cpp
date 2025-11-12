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
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n=10,m=0;
	m=1;
	cout<<n<<' '<<m<<'\n';
	F(i,1,n)cout<<(rnd()&1);
	cout<<'\n';
	F(i,1,n)cout<<rnd()%(n+1)<<" \n"[i==n];
	return 0;
}
