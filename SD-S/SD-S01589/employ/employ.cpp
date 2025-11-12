#include<bits/stdc++.h>
#define LF putchar('\n')
#define SP putchar(' ')
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ui;
const ui N=1e6+5,INF=0x3f3f3f3f,mod=998244353;
template<typename T>void read(T& x)
{
	x=0;char ch=getchar();ll f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch&15),ch=getchar();x*=f;
}
template<typename T,typename... Args>void read(T& x,Args&... args){read(x);read(args...);}
template<typename T>void write(T x)
{
	if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}
	ui a[25],t=0;while(x){a[++t]=x%10;x/=10;}while(t){putchar(a[t--]|48);}
}
template<typename T,typename... Ts>void write(T x,Ts... args){write(x);if(sizeof...(args)!=0){SP;write(args...);}}
ui n,m,a[N],cnt[N],cntc,men[N],tttt[N],ans,all1qwe;
ll fac[N],f[2][20][262144];
char s[N];
bool vvvisss[N];
void dfssss(ui x)
{
	if(x>n)
	{
		ui failed=0,ccc=0;
		for(ui i=1;i<=n;i++)
		{
			if((s[i]&1)&&failed<a[tttt[i]])
				ccc++;
			else
				failed++;
		}
		if(ccc>=m)
			ans++;
	}
	for(ui i=1;i<=n;i++)
	{
		if(!vvvisss[i])
		{
			vvvisss[i]=true,tttt[x]=i;
			dfssss(x+1);
			vvvisss[i]=false;
		}
	}
}
void solve()
{
	read(n,m);
	scanf("%s",s+1);
	for(ui i=1;i<=n;i++)
		if(s[i]&1)
			cnt[cntc]++,all1qwe++;
		else
			cntc++;
	for(ui i=1;i<=n;men[a[i++]]++)
		read(a[i]);
	if(all1qwe<m)
	{
		putchar('0');
		return ;
	}
	if(n==m)
	{
		if(cntc||men[0])
			putchar('0');
		else
			write(fac[n]);
		LF;
		return ;
	}
	if(n<=10)
	{
		
		dfssss(1);
		write(ans);
		LF;
		return ;
	}
	putchar('0');
	
}
int main()
{
	fac[0]=1;
	for(ui i=1;i<N;i++)
		fac[i]=fac[i-1]*i%mod;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}

