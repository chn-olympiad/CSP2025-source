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

#define modd modd1
//#define eps 
//#define inf

#define maxn 200005
#define maxm 5000005
#define d 29



using namespace std;

int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }
int pw (int x,LL mi) { int rt=1; for (;mi;mi>=1,MUL(x,x)) if (mi&1) MUL(rt,x); return rt; }
/*
int sum[],inv[]; void Init ()
{
	int p=0;
	sum[1]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/

int n,q,lx[maxn],ly[maxn],la[maxn],lb[maxn];
string x[maxn],y[maxn],a[maxn],b[maxn];



int p[maxm]; void INit () { p[0]=1; for (int i=1;i<maxm;i++) p[i]=mul(p[i-1],d); }

string na,nb,nx,ny; int al,bl,xl,yl,nl,nr,len;
int ha[maxm],hb[maxm],hx[maxm],hy[maxm]; LL cnt;
int geta (int l,int r) { return add(ha[r],-mul(ha[l-1],p[r-l+1])); }
int getb (int l,int r) { return add(hb[r],-mul(hb[l-1],p[r-l+1])); }
int getx (int l,int r) { return add(hx[r],-mul(hx[l-1],p[r-l+1])); }
int gety (int l,int r) { return add(hy[r],-mul(hy[l-1],p[r-l+1])); }


void worka ()
{
	for (int i=1;i+len-1<=xl;i++)
		if (geta(nl,nr)==getx(i,i+len-1)&&getb(nl,nr)==gety(i,i+len-1)&&
		geta(nl-i+1,nr+xl-(i+len-1))==hx[xl]&&getb(nl-i+1,nr+xl-(i+len-1))==hy[xl]) cnt++;
	/*
	{
		int l,r,ans,ls,rs;
		l=0,r=min(nl,i)-1; while (l<=r)
		{
			if (geta(nl-mid+1,nl-1)==getx(i-mid+1,i-1)&&
				getb(nl-mid+1,nl-1)==gety(i-mid+1,i-1))
				ans=mid,l=mid+1;
			else r=mid-1;
		}	ls=ans+1;
		l=0,r=min(al-nr,xl-(i+len-1)); while (l<=r)
		{
			if (geta(nr+1,nr+mid)==getx(i+len,i+len+mid-1)&&
				getb(nr+1,nr+mid)==gety(i+len,i+len+mid-1))
				ans=mid,l=mid+1;
			else r=mid-1;
		}	rs=ans+1;
		cnt+=1LL*ls*rs;
	}
	*/
}
void solvea ()
{
	for (int t=1;t<=q;t++)
	{
		na=a[t],nb=b[t],al=la[t],bl=lb[t]; cnt=nl=nr=0;
		if (al!=bl) { cout<<0<<'\n'; continue; }
		for (int i=1;i<=al;i++)
			if (!nl&&na[i-1]!=nb[i-1]) nl=i; else if (nl&&!nr&&na[i-1]==nb[i-1]) nr=i-1;
			else if (nr&&na[i-1]!=nb[i-1]) { cout<<0<<'\n'; continue; } len=nr-nl+1;
		for (int i=0;i<=al+1;i++) ha[i]=0;
		for (int i=0;i<=bl+1;i++) hb[i]=0;
		for (int i=1;i<=al;i++) ha[i]=add(mul(ha[i-1],d),na[i-1]-'a'+1);
		for (int i=1;i<=bl;i++) hb[i]=add(mul(hb[i-1],d),nb[i-1]-'a'+1);
		for (int k=1;k<=n;k++)
		{
			nx=x[k],ny=y[k],xl=lx[k],yl=ly[k];
			for (int i=0;i<=xl+1;i++) hx[i]=0;
			for (int i=0;i<=yl+1;i++) hy[i]=0;
			for (int i=1;i<=xl;i++) hx[i]=add(mul(hx[i-1],d),nx[i-1]-'a'+1);
			for (int i=1;i<=yl;i++) hy[i]=add(mul(hy[i-1],d),ny[i-1]-'a'+1);
			worka();
		}	cout<<cnt<<'\n';
	}
}




void work ()
{
	cin>>n>>q; INit();
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i],lx[i]=x[i].si,ly[i]=y[i].si;
	for (int i=1;i<=q;i++) cin>>a[i]>>b[i],la[i]=a[i].si,lb[i]=b[i].si;
	//if (chb()) solveb(); else 
	solvea();
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
//	int T; cin>>T; while (T--)
		work(); return 0;
}
// QAQ 
//飞起来 ~ 
// replace


/*

1 1
a b
cac cbc

*/
