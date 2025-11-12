#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],Sum[500005],b[500005],pr[500005];
map<int,vector<int> > mm;
vector<pair<int,int> > vp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]^a[i];
	for(int i=0;i<=n;i++){
		mm[Sum[i]].push_back(i);
		b[i]=k^Sum[i];
	}int ans=0;
	for(int i=n;i>=1;){
		int nd=b[i];//cout<<"Now: "<<i<<' '<<"Need: "<<nd<<endl;
		if(mm.count(nd) && mm[nd].size()){
			//cout<<"Succeed: "<<i<<endl;
			int t=mm[nd].size();
			while(t&&mm[nd][t-1]>=i){
				mm[nd].pop_back();t--;
			}
			if(t){//cout<<"OK: "<<i<<endl;
				pr[i]=mm[nd][t-1];
				//cout<<"OK: "<<i<<" to: "<<pr[i]<<endl;
				//mm[nd].pop_back();
				//ans++;
				vp.push_back(make_pair(i,pr[i]));
			}
			else{
				//cout<<"Fail: "<<i<<endl;
				pr[i]=-1;
			}
		}
		else{
			//cout<<"Fail: "<<i<<endl;
			pr[i]=-1;
		}
		i--;
	}
	/*sort(vp.begin(),vp.end());*/int maxr=0;
	for(int i=vp.size()-1;i>=0;i--){
		int l=vp[i].second,r=vp[i].first;
		if(l>=maxr){
			maxr=r;
			ans++;
		}
	}cout<<ans<<endl;
	return 0;
}
/*
4 0
2 1 0 3
*/
