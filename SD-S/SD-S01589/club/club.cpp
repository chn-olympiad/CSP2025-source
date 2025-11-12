#include<bits/stdc++.h>
#define LF putchar('\n')
#define SP putchar(' ')
using namespace std;
typedef unsigned int ui;
const ui N=1e5+5;
template<typename T>void read(T& x)
{
	x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
}
template<typename T,typename... Args>void read(T& x,Args&... args){read(x);read(args...);}
template<typename T>void write(T x)
{
	if(x==0){putchar('0');return ;}
	ui a[25],t=0;while(x){a[++t]=x%10;x/=10;}while(t){putchar(a[t--]|48);}
}
template<typename T,typename... Ts>void write(T x,Ts... args){write(x);if(sizeof...(args)!=0){SP;write(args...);}}
ui n,a[3],cnt,cnt1,cnt2,mi[N],mi1[N],mi2[N],ans;
ui check(ui a,ui b,ui c){if(a>=b&&a>=c)return 0;if(b>=c)return 1;return 2;}
void solve()
{
	read(n);
	ans=cnt1=cnt2=cnt=0;
	for(ui i=1;i<=n;i++)
	{
		read(a[0],a[1],a[2]);
		ui t=check(a[0],a[1],a[2]);
		ans+=a[t];
		if(t==1)
		{
			if(a[0]>a[2])
				mi1[cnt1++]=a[1]-a[0];
			else
				mi1[cnt1++]=a[1]-a[2];
		}
		else if(t)
		{
			if(a[0]>a[1])
				mi2[cnt2++]=a[2]-a[0];
			else
				mi2[cnt2++]=a[2]-a[1];
		}
		else
		{
			if(a[1]>a[2])
				mi[cnt++]=a[0]-a[1];
			else
				mi[cnt++]=a[0]-a[2];
		}
	}
	if(cnt>n>>1)
	{
		sort(mi,mi+cnt);
		for(ui i=0;cnt>n>>1;i++,cnt--)
			ans-=mi[i];
	}
	else if(cnt1>n>>1)
	{
		sort(mi1,mi1+cnt1);
		for(ui i=0;cnt1>n>>1;i++,cnt1--)
			ans-=mi1[i];
	}
	else if(cnt2>n>>1)
	{
		sort(mi2,mi2+cnt2);
		for(ui i=0;cnt2>n>>1;i++,cnt2--)
			ans-=mi2[i];
	}
	write(ans);
	LF;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ui T;
	read(T);
	while(T--)
		solve();
	return 0;
}
