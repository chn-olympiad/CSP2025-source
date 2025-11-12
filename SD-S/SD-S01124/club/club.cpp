#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
ll n;
ll a[maxn];
ll b[maxn];
ll c[maxn];
struct node {
	ll a,b,c;
}p[maxn];
bool cmp(node x,node y) {
	return max(x.a,max(x.b,x.c))-(x.a+x.b+x.c-max(x.a,max(x.b,x.c))-min(x.a,min(x.b,x.c))) > max(y.a,max(y.b,y.c))-(y.a+y.b+y.c-max(y.a,max(y.b,y.c))-min(y.a,min(y.b,y.c)));
}
ll cnt[5];
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--) {
		memset(cnt,0,sizeof cnt);
		scanf("%lld",&n);
		for(int i=1;i<=n;++i) {
			scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);	
		}
		ll lim = (n/2);
		ll ans=0;
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;++i) {
			ll x,z;
			ll mid;
			if(p[i].a>=p[i].b && p[i].b>=p[i].c) x = 1 ,mid=2, z = 3;
			else if(p[i].a >= p[i].c && p[i].c >= p[i].b) x = 1 ,mid = 3 ,z = 2;
			else if(p[i].b >= p[i].c && p[i].c >= p[i].a) x = 2 , mid = 3 , z= 1;
			else if(p[i].b >= p[i].a && p[i].a >= p[i].c) x = 2 , mid = 1 ,z=3;
			else if (p[i].c >= p[i].a && p[i].a >= p[i].b) x=3,mid=1 , z=2;
			else if(p[i].c >= p[i].b && p[i].b >= p[i].a) x = 3,mid=2,z=1;
			if(cnt[x] < lim) {
				if(x == 1) {
					ans += p[i].a ;
				} 
				else if(x == 2) {
					ans += p[i].b;
				}
				else ans += p[i].c;
				cnt[x]++;
			}
			else if(cnt[mid] < lim) {
				if(mid==1) {
					ans += p[i].a ;
				} 
				else if(mid == 2) {
					ans += p[i].b;
				}
				else ans += p[i].c;
				cnt[mid]++;
			}
			else if(cnt[z] < lim) {
				if(z == 1) {
					ans += p[i].a ;
				} 
				else if(z == 2) {
					ans += p[i].b;
				}
				else ans += p[i].c;
				cnt[z] ++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}



/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8 
4 0 0



*/
