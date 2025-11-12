#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n; 
int a[N][3];
vector<int> v[3],w;
int cnt[3];
void solve(){
	for(int i=0;i<3;i++){
		v[i].clear();
		cnt[i]=0;
	}
	w.clear();
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
		int x=0,mx=a[i][0];
		for(int j=1;j<3;j++){
			if(a[i][j]>mx){
				x=j;
				mx=a[i][j];
			}
		}
		v[x].push_back(i);
		cnt[x]++;
		ans+=a[i][x];
	}
	if(cnt[0]>n/2){
		for(auto i:v[0]){
			w.push_back(a[i][0]-max(a[i][1],a[i][2]));
		}
		sort(w.begin(),w.end());
		int now=0;
		for(auto i:w){
			ans-=i;
			now++;
			if(now==cnt[0]-n/2){
				break;
			}
		}
	}else if(cnt[1]>n/2){
		for(auto i:v[1]){
			w.push_back(a[i][1]-max(a[i][0],a[i][2]));
		}
		sort(w.begin(),w.end());
		int now=0;
		for(auto i:w){
			ans-=i;
			now++;
			if(now==cnt[1]-n/2){
				break;
			}
		}
	}else if(cnt[2]>n/2){
		for(auto i:v[2]){
			w.push_back(a[i][2]-max(a[i][1],a[i][0]));
		}
		sort(w.begin(),w.end());
		int now=0;
		for(auto i:w){
			ans-=i;
			now++;
			if(now==cnt[2]-n/2){
				break;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
