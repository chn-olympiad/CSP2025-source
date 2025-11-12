#include <bits/stdc++.h>

using namespace std;

#define gc() getchar()
#define pc(x) putchar(x)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'

inline int read()
{
	int x=0,f=1;char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c)) {x=x*10+c-'0';c=gc();}
	return x*f;
}

inline void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');}
	else {write(x/10);pc(x%10+'0');}
	return ;
}

inline void print(int x)
{
	write(x);pc('\n');
	return ;
}

int T;
int n;
struct node {int x,y,z;};
node a[100010];

bool cmp(node X,node Y)
{
	return X.x-X.y>Y.x-Y.y;
}


void solve()
{
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	}
	int cnta=0,cntb=0,cntc=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {ans+=a[i].x;cnta++;}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) {ans+=a[i].y;cntb++;}
		else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) {ans+=a[i].z;cntc++;}
	}
	if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2) {print(ans);return ;}
	if(cntb>n/2)
	{
		swap(cntb,cnta);
		for(int i=1;i<=n;i++) {swap(a[i].x,a[i].y);}
	}
	else if(cntc>n/2) 
	{
		swap(cntc,cnta);
		for(int i=1;i<=n;i++) {swap(a[i].x,a[i].z);}
	}
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z) 
		{
			q.push(max(a[i].y-a[i].x,a[i].z-a[i].x));
		}
	}
	while(cnta>n/2)
	{
		cnta--;
		ans+=q.top();
		q.pop();
	}
	print(ans);
	return ;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {solve();}
	return 0;
}

//100pts
