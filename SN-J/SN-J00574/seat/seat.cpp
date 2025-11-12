//SN-J00574  lizhiying  ¸¨ÂÖÖÐÑ§ 

#include <bits/stdc++.h>
#define LL long long
#define DB double
#define LB long double
#define mid ((l+r)>>1)
#define tp top()
#define pp pop()
#define si size()
#define modd1 998244353
#define modd2 1000000007
#define eps1 (-1e9)
#define eps2 (-1e18)
//#define modd 
//#define eps 

#define maxn 105





using namespace std;
/*
int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }

int sum[],inv[]; void Init ()
{
	int p=;
	sum[0]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/


int n,m,a[maxn],t;







void work ()
{
	cin>>n>>m; for (int i=1;i<=n*m;i++) cin>>a[i],a[i]=-a[i];
	t=a[1]; sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++) if (a[i]==t)
	{
		int p=(i+n-1)/n,q=i-(p-1)*n;
		if (p%2==1) cout<<p<<' '<<q;
		else cout<<p<<' '<<n-q+1;
		return ; 
	}
	
	
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
	//int T; cin>>T; while (T--)
		work(); return 0;
}
//seat
//csyyyy121
