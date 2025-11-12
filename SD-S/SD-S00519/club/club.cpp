#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define gtc getchar
#define ptc putchar
inline ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
inline void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void println(ll x){ write(x),ptc('\n'); }
inline void printsp(ll x){ write(x),ptc(' '); }
const int maxn=1e5+6;
struct node{
	int a,b,c;
	int mx=-1,id,px=-1;
	void scan(){
		a=read(),b=read(),c=read();
	} 
	void figure(){
		mx=max({a,b,c});
		if(mx==a) px=max(b,c),id=1;
		else if(mx==b) px=max(a,c),id=2;
		else px=max(a,b),id=3;
	}
};
node a[maxn];
int n,num[5];

bool cmp(node x,node y){
	return x.mx+y.px>x.px+y.mx;
}

void init(){
	num[0]=num[1]=num[2]=num[3]=0;
}
void solve(){
	n=read();
	init();
	for(int i=1;i<=n;i++) a[i].scan(),a[i].figure();
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(num[a[i].id]!=n/2){
			ans+=a[i].mx;
			num[a[i].id]++;
		}else{
			ans+=a[i].px;
			//直接不用记录了，剩下的一定<n/2 
		}
	}
	println(ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
/*
Ren5Jie4Di4Ling5%

真的对么？ 
*/
