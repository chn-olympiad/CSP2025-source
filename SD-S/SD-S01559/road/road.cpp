#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
const int M=2e6+10;
struct Nodee{
	ll frm;
	ll tgt;
	ll bianq;
	friend bool operator <(const Nodee a,const Nodee b){
		return a.bianq<b.bianq;
	}
}edgs[M];
ll fath[N],vil[N],n,m,u,v,k;
bool flgg;
ll distt,ans,edgcnt;
ll fdfa(ll ndee){
	if(fath[ndee]==ndee) return ndee;
	return fath[ndee]=fdfa(fath[ndee]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	flgg=1;
	for(int i=1;i<=m;i++) cin>>edgs[i].frm>>edgs[i].tgt>>edgs[i].bianq;
	if(!k){
		for(int i=1;i<=k;i++){
			cin>>vil[i];
			if(vil[i]!=0) flgg=0;
			for(int j=1;j<=n;j++){
				cin>>distt;
			}
		}
		for(int i=1;i<=n;i++) fath[i]=i;
		sort(edgs+1,edgs+m+1);
		for(int i=1;i<=m;i++){
			ll fafr=fdfa(edgs[i].frm),fatg=fdfa(edgs[i].tgt);
			if(fafr==fatg) continue;
			ans+=edgs[i].bianq;
			edgcnt++;
			if(edgcnt==n-1) break;
		}
		cout<<ans<<'\n';
		return 0;
	}
	else{
		ll cntt=m;
		for(int i=1;i<=k;i++){
			cin>>vil[i];
			vector<ll>vec,ndid;
			vec.clear();
			ndid.clear();
			for(int j=1;j<=n;j++){
				cin>>distt;
				vec.push_back(distt);
			}
			for(int j=0;j<n;j++){
				if(!vec[j]){
					ndid.push_back(j+1);
				}
			}
			for(int kkz=0;kkz<(int)ndid.size();kkz++){
				for(int j=0;j<n;j++){
					edgs[++cntt]={ndid[kkz],j+1,vec[j]};
				}
			}
		}
		for(int i=1;i<=n;i++) fath[i]=i;
		sort(edgs+1,edgs+cntt+1);
		for(int i=1;i<=cntt;i++){
			ll fafr=fdfa(edgs[i].frm),fatg=fdfa(edgs[i].tgt);
			if(fafr==fatg) continue;
			ans+=edgs[i].bianq;
			fath[fafr]=fatg;
			edgcnt++;
			if(edgcnt==n-1) break;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}

