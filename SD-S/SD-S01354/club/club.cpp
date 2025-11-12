#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
}
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
struct node{
	int maxn,x,maxid;
}f[N];
int cnt[4];
inline bool cmp(node a,node b){
	return (a.maxid==b.maxid?a.x<b.x:a.maxid<b.maxid);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=qr;
	while(T--){
		int n=qr,ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++){
			int a=qr,b=qr,c=qr;
			if(a>=b&&a>=c){
				f[i].maxn=a;
				f[i].x=a-max(b,c);
				f[i].maxid=1;
			}
			if(b>=a&&b>=c){
				f[i].maxn=b;
				f[i].x=b-max(a,c);
				f[i].maxid=2;
			}
			if(c>=b&&c>=a){
				f[i].maxn=c;
				f[i].x=c-max(a,b);
				f[i].maxid=3;
			}
			cnt[f[i].maxid]++;
			ans+=f[i].maxn;
		}
		if(cnt[1]>(n>>1)||cnt[2]>(n>>1)||cnt[3]>(n>>1)){
			int mxid=1;
			if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) mxid=1;
			if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) mxid=2;
			if(cnt[3]>=cnt[1]&&cnt[3]>=cnt[2]) mxid=3;
			sort(f+1,f+n+1,cmp);
			int l=0,r;
			for(int i=1;i<=n;i++){
				if(f[i].maxid==mxid){
					if(cnt[mxid]<=(n>>1)) break;
					ans-=f[i].x;
					cnt[mxid]--;
				}
			}
		}
		qwe(ans);
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
