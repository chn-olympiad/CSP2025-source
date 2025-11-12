#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt[4],ans,now1,now2,now3;
struct opp{
	int d[4];
}a[201000];
bool cmp(opp x,opp y){
	int mx=max(x.d[1],max(x.d[2],x.d[3])),dx;
	if(mx==x.d[1])dx=max(x.d[2],x.d[3]);
	if(mx==x.d[2])dx=max(x.d[1],x.d[3]);
	if(mx==x.d[3])dx=max(x.d[2],x.d[1]);
	int my=max(y.d[1],max(y.d[2],y.d[3])),dy;
	if(my==y.d[1])dy=max(y.d[2],y.d[3]);
	if(my==y.d[2])dy=max(y.d[1],y.d[3]);
	if(my==y.d[3])dy=max(y.d[2],y.d[1]);
	if(mx-dx==my-dy)return dx>dy;
	return mx-dx>my-dy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].d[1]<<" "<<a[i].d[2]<<" "<<a[i].d[3]<<endl;
//		}
		for(int i=1;i<=n;i++){
			int mx=max(a[i].d[1],max(a[i].d[2],a[i].d[3])),dx;
			if(mx==a[i].d[1])dx=max(a[i].d[2],a[i].d[3]);
			if(mx==a[i].d[2])dx=max(a[i].d[1],a[i].d[3]);
			if(mx==a[i].d[3])dx=max(a[i].d[2],a[i].d[1]);
			if(mx==a[i].d[1])mx=1;
			else if(mx==a[i].d[2])mx=2;
			else if(mx==a[i].d[3])mx=3;
			if(dx==a[i].d[1])dx=1;
			else if(dx==a[i].d[2])dx=2;
			else if(dx==a[i].d[3])dx=3;
			if(cnt[mx]<n/2)ans+=a[i].d[mx],cnt[mx]++;
			else ans+=a[i].d[dx],cnt[dx]++;
		}
		cout<<ans<<endl;
	}
}
