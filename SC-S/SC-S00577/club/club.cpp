#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5;
int n,a[maxn+5][4],cnt[4],bel[maxn+5];
void solve(){
	cin>>n;cnt[1]=cnt[2]=cnt[3]=0;
	int ans=0,lim=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max({a[i][1],a[i][2],a[i][3]});
		ans+=mx;
		if(mx==a[i][1])cnt[1]++,bel[i]=1;
		else if(mx==a[i][2])cnt[2]++,bel[i]=2;
		else cnt[3]++,bel[i]=3;
	}
	if(cnt[1]<=lim&&cnt[2]<=lim&&cnt[3]<=lim)return cout<<ans<<"\n",void();
	int aim=0,num=0;
	if(cnt[1]>lim)aim=1,num=cnt[1]-lim;
	if(cnt[2]>lim)aim=2,num=cnt[2]-lim;
	if(cnt[3]>lim)aim=3,num=cnt[3]-lim;
	vector <int> Q;
	for(int i=1;i<=n;i++)if(bel[i]==aim){
		sort(a[i]+1,a[i]+4);
		Q.emplace_back(a[i][3]-a[i][2]);
	}
	sort(Q.begin(),Q.end());
	for(int i=0;i<num;i++)ans-=Q[i];
	cout<<ans<<"\n";
}//考虑只有一个超标,那么直接从小往大舍去即可
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin>>test;
	while(test--)solve();
	return 0;
}