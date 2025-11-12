#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define Fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define fre(k) freopen(k".in","r",stdin),freopen(k".out","w",stdout)
using namespace std;
const int N=1e5+10;
int T,n,c[5],ans;
struct nd{int v,d,k;};
struct node{nd f[5];}a[N];
bool cmp(nd a,nd b){return a.v>b.v;}
bool cmp2(node a,node b){
	if(a.f[1].k==b.f[1].k) return a.f[2].k>b.f[2].k;
	return a.f[1].k>b.f[1].k;
}
signed main(){
	fre("club");
	Fast;cin>>T;
	while(T--){
		cin>>n;c[1]=c[2]=c[3]=0;ans=0;
		rep(i,1,n)rep(j,1,3){
			cin>>a[i].f[j].v;
			a[i].f[j].d=j;
		}
		rep(i,1,n){
			sort(a[i].f+1,a[i].f+4,cmp);
			rep(j,1,2) a[i].f[j].k=a[i].f[j].v-a[i].f[j+1].v;
		}
		sort(a+1,a+n+1,cmp2);
		rep(i,1,n)rep(j,1,3)if(c[a[i].f[j].d]<n/2){
			c[a[i].f[j].d]++,ans+=a[i].f[j].v;break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
