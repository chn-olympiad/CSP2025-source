#include<bits/stdc++.h>

using namespace std;

#define int long long

int pre(int x){
	if(x==1)
		return 3;
	return x-1;
}

int nxt(int x){
	if(x==3)
		return 1;
	return x+1;
}

void solve(){
	int n;
	cin>>n;
	int a[n+1][4];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	vector<int> v[4];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]>=a[i][pre(j)]&&a[i][j]>=a[i][nxt(j)]){
				ans+=a[i][j];
				//cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
				v[j].push_back(min(a[i][j]-a[i][pre(j)],a[i][j]-a[i][nxt(j)]));
				break;
			}
		}
	}
	for(int i=1;i<=3;i++){
		//cout<<v[i].size()<<" ";
		sort(v[i].begin(),v[i].end(),greater<int>());
		if(v[i].empty()){
			continue;
		}
		else{
			for(int j=v[i].size()-1;j>=n/2;j--){
				ans-=v[i][j];
			}
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

