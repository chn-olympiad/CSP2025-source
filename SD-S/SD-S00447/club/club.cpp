#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[(int)1e5+10][10];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ll ans=0;
		ll cnt[10]={0};
		vector<ll>b[10];
		for(ll i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				ans+=a[i][1];
				b[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				ans+=a[i][2];
				b[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				cnt[3]++;
				ans+=a[i][3];
				b[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
			}
		} 
		for(ll i=1;i<=3;i++){
			if(cnt[i]>(n/2)){
				sort(b[i].begin(),b[i].end());
				for(int j=0;cnt[i]>(n/2);j++){
					ans-=b[i][j]; 
					cnt[i]--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

