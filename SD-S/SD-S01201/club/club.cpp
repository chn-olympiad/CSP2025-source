#include<bits/stdc++.h>
using namespace std;
namespace lkwbian{
	using ll=long long;
	using pii=pair<int,int>;
	#define fi first
	#define se second
	#define mp make_pair
	#define pb emplace_back
	const int N=100005;
	int T,n;
	int cnt[3];
	vector<int>vc[3];
	void Main(){
		cin.tie(nullptr)->sync_with_stdio(0);
		cin>>T;
		while(T--){
			cin>>n;
			long long ans=0;
			cnt[0]=cnt[1]=cnt[2]=0;
			vc[0].clear(),vc[1].clear(),vc[2].clear();
			for(int i=1,x,y,z,mn,cm;i<=n;i++){
				cin>>x>>y>>z;
				mn=max({x,y,z});
				ans+=mn;
				if(x==mn){
					cnt[0]++;
					cm=max(y,z);
					vc[0].pb(cm-mn);
					continue;
				}
				if(y==mn){
					cnt[1]++;
					cm=max(x,z);
					vc[1].pb(cm-mn);
					continue;
				}
				if(z==mn){
					cnt[2]++;
					cm=max(x,y);
					vc[2].pb(cm-mn);
					continue;
				}
			}
			n>>=1;
			if(cnt[0]>n){
				int t=cnt[0]-n;
				sort(vc[0].begin(),vc[0].end(),greater<int>());
				for(int i=0;i<t;i++)
					ans+=vc[0][i];
			}
			else if(cnt[1]>n){
				int t=cnt[1]-n;
				sort(vc[1].begin(),vc[1].end(),greater<int>());
				for(int i=0;i<t;i++)
					ans+=vc[1][i];
			}else if(cnt[2]>n){
				int t=cnt[2]-n;
				sort(vc[2].begin(),vc[2].end(),greater<int>());
				for(int i=0;i<t;i++)
					ans+=vc[2][i];
			}
			cout<<ans<<'\n';
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	lkwbian::Main();
	return 0;
}
//Ren5Jie4Di4Ling5% 
// A: 17min 
