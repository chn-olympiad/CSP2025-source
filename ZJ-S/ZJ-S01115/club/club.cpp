#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
	int fi,se,th;
	int fid;
}a[N];
int n,cnt[4],ans;
int t;
bool cmp(node x,node y){
	if(x.fid!=y.fid){
		return (x.fid==t);
	}
	return x.fi-x.se<y.fi-y.se;
}
bool cmp2(node x,node y){
	return y.se-y.th>x.se-x.th;
}
void solve(){
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		a[i].a=a[i].b=a[i].c=a[i].fi=a[i].se=a[i].th=0;
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].fi=max(a[i].a,max(a[i].b,a[i].c));
		a[i].th=min(a[i].a,min(a[i].b,a[i].c));
		a[i].se=a[i].a+a[i].b+a[i].c-a[i].fi-a[i].th;
	}
	for(int i=1;i<=n;i++){
		if(a[i].fi==a[i].a){
			a[i].fid=1;
			cnt[1]++;
		}
		else if(a[i].fi==a[i].b){
			cnt[2]++;
			a[i].fid=2;
		}
		else if(a[i].fi==a[i].c){
			a[i].fid=3;
			cnt[3]++;
		}
		ans+=a[i].fi;
	}
	sort(a+1,a+n+1,cmp);
	if(cnt[1]>n/2){
		t=1;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=cnt[1]-n/2;i++){
			ans-=a[i].fi;
			ans+=a[i].se;
		}
	}else if(cnt[2]>n/2){
		t=2;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=cnt[2]-n/2;i++){
			ans-=a[i].fi;
			ans+=a[i].se;
		}
	}else if(cnt[3]>n/2){
		t=3;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=cnt[3]-n/2;i++){
			ans-=a[i].fi;
			ans+=a[i].se;
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
