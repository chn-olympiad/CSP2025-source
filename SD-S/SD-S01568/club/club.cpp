#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		vector<vector<int>>val(3);
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			int maxn=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=maxn;
			if(maxn==a[i][0])
				val[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
			else if(maxn==a[i][1])
				val[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
			else
				val[2].push_back(a[i][2]-max(a[i][0],a[i][1]));
		}
		sort(val.begin(),val.end(),[&](const vector<int> &a,const vector<int> &b){
			return a.size()>b.size();
		});
		sort(val[0].begin(),val[0].end(),greater<int>());
		while((int)val[0].size()>n/2){
			ans-=val[0].back();
			val[0].pop_back();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
