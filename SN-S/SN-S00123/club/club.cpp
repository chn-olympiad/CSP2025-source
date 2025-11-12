#include<iostream>
#include<algorithm>
#include<vector>
#define  int  long long
using namespace std;
int n,a[4],sum,cnt[4];
vector<int> v[4];
void solve(){
	sum=0,a[1]=a[2]=a[3]=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	v[1].clear(),v[2].clear(),v[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]>=a[2]&&a[1]>=a[3]){
			cnt[1]++; sum+=a[1];
			v[1].push_back(a[1]-max(a[2],a[3]));
		}else if(a[2]>=a[1]&&a[2]>=a[3]){
			cnt[2]++; sum+=a[2];
			v[2].push_back(a[2]-max(a[1],a[3]));
		}else {
			cnt[3]++; sum+=a[3];
			v[3].push_back(a[3]-max(a[1],a[2]));
		}
	}
	sort(v[1].begin(),v[1].end(),greater<int>());
	sort(v[2].begin(),v[2].end(),greater<int>());
	sort(v[3].begin(),v[3].end(),greater<int>());
	while(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		if(cnt[1]>n/2){
			sum-=*v[1].rbegin();
			v[1].pop_back();
			cnt[1]--;
		}else if(cnt[2]>n/2){
			sum-=*v[2].rbegin();
			v[2].pop_back();
			cnt[2]--;
		}else {
			sum-=*v[3].rbegin();
			v[3].pop_back();
			cnt[3]--;
		}
	}cout<<sum<<'\n';
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>T; while(T--)solve();
	return 0;
}
/*
3 
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0




*/
