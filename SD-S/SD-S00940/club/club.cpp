#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n,rt;
ll a[N][3],ans;
vector<int> num[3];
vector<ll> coc;
void solve(){
	scanf("%d",&n); rt=ans=0; coc.clear();
	for(int i=0;i<3;i++) num[i].clear();
	for(int i=1;i<=n;i++){
		int id=0;
		for(int j=0;j<3;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]>a[i][id]) id=j;
		}
		num[id].push_back(i); ans+=a[i][id];
		if(num[id].size()>num[rt].size()) rt=id;
	}
	if(num[rt].size()<=n/2){
		cout<<ans<<"\n"; return;
	}
	for(int v:num[rt]){
		int id=-1;
		for(int i=0;i<3;i++){
			if(i==rt) continue;
			if(id==-1||a[v][i]>a[v][id]) id=i;
		}
		coc.push_back(a[v][rt]-a[v][id]);
	}
	sort(coc.begin(),coc.end());
	for(int i=1;i<=num[rt].size()-n/2;i++) ans-=coc[i-1];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
} 
