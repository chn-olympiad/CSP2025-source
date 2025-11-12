#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
int q,n,cnt[5]={0},k=0,po,ans=0;
struct p{
	int a1,a2,a3,t,ch,to_;
}a[N];
int solve(int x,int y,int z){
	if(x>=y) swap(x,y);
	if(y>=z) swap(y,z);
	if(x>=y) swap(x,y);
	return z-y;
}
int ma(int x,int y,int z){
	int xx=max(x,max(y,z));
	if(x==xx) return 1;
	if(y==xx) return 2;
	if(z==xx) return 3;
}
bool cmp(p x,p y){
	if(x.to_==po&&y.to_!=po) return 1;
	if(x.to_!=po&&y.to_==po) return 0;
	return x.t<y.t;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&q);
	while(q--){
		k=0;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			a[i].t=solve(a[i].a1,a[i].a2,a[i].a3);
			a[i].ch=max(a[i].a1,max(a[i].a2,a[i].a3));
			cnt[ma(a[i].a1,a[i].a2,a[i].a3)]++;
			a[i].to_=ma(a[i].a1,a[i].a2,a[i].a3);
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				k=cnt[i]-n/2;
				po=i;
				sort(a+1,a+n+1,cmp);
			}
		}
		for(int i=1;i<=k;i++){
			a[i].ch-=a[i].t;
//			cout<<a[i].a1<<' '<<a[i].a2<<' '<<a[i].a3<<' '<<a[i].to_<<'\n'; 
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].ch;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
