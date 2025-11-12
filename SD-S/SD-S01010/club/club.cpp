#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
struct aa{
	int a,b,c,maxid,cx,ma;
}a[100550];
bool cmt(const aa& x,const aa& y){
	if(x.maxid==y.maxid){
		return x.ma-x.cx>y.ma-y.cx;
	}
	return x.maxid<y.maxid;
}
void solve(){
	memset(a,0,sizeof a);
	int n=read(),cnt=1,res=0;
	for(int i=1;i<=n;++i){
		a[i].a=read();a[i].b=read();a[i].c=read();
		int maxn=max(a[i].a,max(a[i].b,a[i].c)),cd=0;
		if(a[i].a==maxn) a[i].maxid=1,cd=max(a[i].b,a[i].c);
		if(a[i].b==maxn) a[i].maxid=2,cd=max(a[i].a,a[i].c);
		if(a[i].c==maxn) a[i].maxid=3,cd=max(a[i].a,a[i].b);
		a[i].cx=cd;a[i].ma=maxn;
	}
	sort(a+1,a+n+1,cmt);
	for(int i=1;i<=n;++i){
		if(a[i].maxid==a[i-1].maxid) ++cnt;
		else cnt=1;
		if(cnt>n/2){
			res+=a[i].cx;
		}
		else res+=a[i].ma;
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--) solve();
}
