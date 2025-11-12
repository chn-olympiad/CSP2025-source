// SN-S00371  李知颖  辅轮中学
#include <bits/stdc++.h>
#define LL long long
#define DB double
#define LB long double
#define mid ((l+r)>>1)
#define tp top()
#define pp pop()
#define si size()
#define F first
#define S second
#define modd1 998244353
#define modd2 1000000007
#define eps1 (1e-9)
#define eps2 (1e-18)
#define inf1 (1e9)
#define inf2 (1e18)

//#define modd 
//#define eps 
//#define inf

#define maxn 100005




using namespace std;
/*
int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }
int pw (int x,LL mi) { int rt=1; for (;mi;mi>=1,MUL(x,x)) if (mi&1) MUL(rt,x); return rt; }

int sum[],inv[]; void Init ()
{
	int p=0;
	sum[1]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/

int n,a[maxn][3],mx[maxn],cnt[3],p;
priority_queue <int> Q;
LL ans;




void work ()
{
	cin>>n; ans=cnt[0]=cnt[1]=cnt[2]=0; while (Q.si) Q.pp;
	for (int i=1;i<=n;i++) for (int j=0;j<3;j++) cin>>a[i][j];
	for (int i=1;i<=n;i++) mx[i]=max(a[i][0],max(a[i][1],a[i][2]));
	for (int i=1;i<=n;i++)
		if (a[i][0]==mx[i]) cnt[0]++;
		else if (a[i][1]==mx[i]) cnt[1]++;
		else cnt[2]++;
	for (int i=1;i<=n;i++) ans+=mx[i];
	if (cnt[0]>n/2) p=0;
	else if (cnt[1]>n/2) p=1;
	else if (cnt[2]>n/2) p=2;
	else { cout<<ans<<'\n'; return ; }
	if (p) for (int i=1;i<=n;i++) swap(a[i][0],a[i][p]);
	for (int i=1;i<=n;i++) if (a[i][0]==mx[i])
		Q.push(max(a[i][1],a[i][2])-a[i][0]);
	cnt[p]-=n/2; while (cnt[p]--) ans+=Q.tp,Q.pp;
	cout<<ans<<'\n';
	
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
	int T; cin>>T; while (T--)
		work(); return 0;
}
// QAQ 
//飞起来 ~ 
// club
