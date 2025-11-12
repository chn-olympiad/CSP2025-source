#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],fav[N],sec[N],cnt[3],ans;
vector<int> over;
void solve(){
	cin>>n;
	over.clear();
	memset(cnt,0,sizeof cnt);
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) fav[i]=0;
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) fav[i]=1;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]) fav[i]=2;
		if(fav[i]==0){
			if(a[i][1]>=a[i][2]) sec[i]=1;
			else sec[i]=2;
		}else if(fav[i]==1){
			if(a[i][0]>=a[i][2]) sec[i]=0;
			else sec[i]=2;
		}else if(fav[i]==2){
			if(a[i][0]>=a[i][1]) sec[i]=0;
			else sec[i]=1;
		}
		cnt[fav[i]]++;
		ans+=a[i][fav[i]];
	}
	for(int i=0;i<=2;i++){
		if(cnt[i]>n/2){
			for(int j=1;j<=n;j++){
				if(fav[j]==i) over.push_back(a[j][fav[j]]-a[j][sec[j]]);
			}
			sort(over.begin(),over.end());
			for(int j=0;cnt[i]-j>n/2;j++) ans-=over[j];
			break;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
