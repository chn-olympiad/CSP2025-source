#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct chose{
	int p,num;
	bool operator <(const chose com)const{
		return num>com.num;
	}
};
struct person{
	chose a[4];
	int l;
}a[N];
int cnt[4];
int n;
bool cmp(person a,person b){
	return a.l>b.l;
}
void solve(){
	int ans=0;
	cin>>n;
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a[1].num>>a[i].a[2].num>>a[i].a[3].num;
		a[i].a[1].p=1,a[i].a[2].p=2,a[i].a[3].p=3;
		sort(a[i].a+1,a[i].a+4);
		a[i].l=a[i].a[1].num-a[i].a[2].num;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(cnt[a[i].a[1].p]==n/2){
			if(cnt[a[i].a[2].p]==n/2){
				cnt[a[i].a[3].p]++;
				ans+=a[i].a[3].num;
			}else{
				cnt[a[i].a[2].p]++;
				ans+=a[i].a[2].num;
			}
		}else{
			cnt[a[i].a[1].p]++;
			ans+=a[i].a[1].num;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	} 
	return 0;
}

