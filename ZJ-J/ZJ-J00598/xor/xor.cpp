#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >vec;
int sum[500005];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}
vector<int>cnt[2100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		sum[i]=sum[i-1]^x;
		cnt[sum[i]].push_back(i);
	}
	int prer=n+1;
	for(int i=n;i>=1;i--){
//		for(int j=i;j<prer;j++){
//			if((sum[i-1]^k)==sum[j]){
//				vec.push_back({i,j});
//				prer=j;
//				break;
//			}
//		}
		int pos=sum[i-1]^k;
		int x=lower_bound(cnt[pos].begin(),cnt[pos].end(),i)-cnt[pos].begin();
		if(x>=cnt[pos].size()||cnt[pos][x]>=prer)continue;
		vec.push_back({i,cnt[pos][x]});
		prer=cnt[pos][x];
	}
	sort(vec.begin(),vec.end(),cmp);
	prer=0;
	int ans=0;
	for(int i=0;i<vec.size();i++){
		if(prer<vec[i].first){
			prer=vec[i].second;
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//9:27 300pts
//already to sleep
