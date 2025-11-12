#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct ddd{
	ll w,a1,b1,c1,g;
};
ll T,n,ans,p;
ll maxx;
ll a[N],b[N],c[N];
void init(){
	maxx=-0x3f3f3f3f;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
}
void bfs(){
	queue<ddd> q;
	q.push({a[1],1,0,0,1});
	q.push({b[1],0,1,0,1});
	q.push({c[1],0,0,1,1});
	while(!q.empty()){
		ll anss=q.front().w;
		ll aa=q.front().a1;
		ll bb=q.front().b1;
		ll cc=q.front().c1;
		ll ge=q.front().g;
		q.pop();
		if(aa<p){
			q.push({anss+a[ge+1],aa+1,bb,cc,ge+1});
		}
		if(bb<p){
			q.push({anss+b[ge+1],aa,bb+1,cc,ge+1});
		}
		if(cc<p){
			q.push({anss+c[ge+1],aa,bb,cc+1,ge+1});
		}
		maxx=max(maxx,anss);
	}
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>T;
	while(T--){
		bool flag=0,flagg=0;
		init();
		scanf("%lld",&n);
		p=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(c[i]!=0){
				flag=1;
			}
			if(b[i]!=0){
				flagg=1;
			}
		}
		if(flag==0&&flagg==0){
			int ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=p;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		bfs();
		cout<<maxx<<'\n';
	}
	return 0;
}
