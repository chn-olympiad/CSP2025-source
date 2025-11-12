#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
constexpr int N=1e5+9;
struct node
{
	int a,b,c;
}a[N];
struct array
{
	int n;
	node a[N];
	void add(node x)
	{
		a[++n]=x;
	}
	void clear()
	{
		n=0;
	}
}A,B,C;
void solve()
{
	A.clear();
	B.clear();
	C.clear();
	int n;
	cin>>n;
	F(i,1,n)cin>>a[i].a>>a[i].b>>a[i].c;
	ll ans=0;
	F(i,1,n)
	{
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c)A.add(a[i]);
		else if(a[i].b>=a[i].c)B.add(a[i]);
		else C.add(a[i]);
		ans+=max({a[i].a,a[i].b,a[i].c});
	}
	if(A.n>n/2)
	{
		sort(A.a+1,A.a+A.n+1,[&](const node&A,const node&B){return A.a-max(A.b,A.c)<B.a-max(B.b,B.c);});
		F(i,1,A.n-n/2)ans-=A.a[i].a-max(A.a[i].b,A.a[i].c);
	}
	if(B.n>n/2)
	{
		sort(B.a+1,B.a+B.n+1,[&](const node&A,const node&B){return A.b-max(A.a,A.c)<B.b-max(B.a,B.c);});
		F(i,1,B.n-n/2)ans-=B.a[i].b-max(B.a[i].a,B.a[i].c);
	}
	if(C.n>n/2)
	{
		sort(C.a+1,C.a+C.n+1,[&](const node&A,const node&C){return A.c-max(A.a,A.b)<C.c-max(C.a,C.b);});
		F(i,1,C.n-n/2)ans-=C.a[i].c-max(C.a[i].a,C.a[i].b);
	}
	cout<<ans<<'\n';
}
int main()
{
	assert(freopen("club.in","r",stdin));
	assert(freopen("club.out","w",stdout));
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
