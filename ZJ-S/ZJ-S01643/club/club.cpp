#include<bits/stdc++.h>
#define int long long
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
#define ff(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
using namespace std;
const int N=1e5+10;
int t;
int n;
struct point {
	int fi,se,th;
	int fid,sid,tid;
}a[N];
int tmp[4],num[4],cnt[4];
bool cmp(point x,point y){
	if(x.fi-x.se==y.fi-y.se)return x.se-x.th>y.se-y.th;
	return x.fi-x.se>y.fi-y.se;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ff("club");
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>num[1]>>num[2]>>num[3];
			tmp[1]=num[1];
			tmp[2]=num[2];
			tmp[3]=num[3];
			sort(tmp+1,tmp+3+1);
			a[i].fi=tmp[3],a[i].se=tmp[2],a[i].th=tmp[1];
			for(int j=1;j<=3;j++){
				if(a[i].fi==num[j]){
					a[i].fid=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i].se==num[j]&&a[i].fid!=j){
					a[i].sid=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i].th==num[j]&&a[i].fid!=j&&a[i].tid!=j){
					a[i].tid=j;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].fid]<n/2){
				cnt[a[i].fid]++;
				ans+=a[i].fi;
			}
			else if(cnt[a[i].sid]<n/2){
				cnt[a[i].sid]++;
				ans+=a[i].se;
			}
			else {
				cnt[a[i].tid]++;
				ans+=a[i].th;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


