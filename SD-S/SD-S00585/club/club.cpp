#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

inline ll read() {
	ll x=0,t=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*t;
}

inline void write(ll x) {
	if(x==0) {
		putchar('0');
		return;
	}
	if(x<0)
		x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

/*

ll qpow(ll x,ll y,ll mod) {
	ll res=1;
	while(y) {
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

*/

const int N=1e5+7;

int a[N][4],h[4],n,ans,vis[N];

struct node{
	int now,x,y,z;
};

int fid(int i) {
	if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
		return 1;
	if(a[i][2]>=a[i][3] && a[i][2]>=a[i][1])
		return 2;
	return 3;
}

int work(int i) {
	int maxn=fid(i);
	if(h[maxn]<n/2) {
		vis[i]=maxn;
		h[maxn]++;
		int res=a[i][maxn];
		return res;
	}
	else {
		int res=a[i][maxn],ljh;
		a[i][maxn]=-1;
		int nw=fid(i),cnt=0,fex=-1,cxk;
		for(int j=i-1;j>=1;j--) {
			if(vis[j]!=maxn)
				continue;
			int ress=a[j][maxn];
			a[j][maxn]=-1;
			cxk=fid(j);
			ljh=a[j][cxk]+res-(a[i][nw]+ress);
			if(ljh>cnt) {
				cnt=ljh;
				fex=j;
			}
			a[j][maxn]=ress;
		}
		a[i][maxn]=res;
		
		if(fex==-1)
			return work(i);
		else {
			vis[fex]=cxk;
			h[cxk]++;
			vis[i]=maxn;
			h[maxn]++;
			return cnt;
		}
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--) {
		memset(h,0,sizeof(h));
		n=read(),ans=0;
		for(int i=1;i<=n;i++)
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		
		for(int i=1;i<=n;i++) {
			ans+=work(i);
		}
		
		write(ans),putchar('\n');
	}
	return 0;
}

