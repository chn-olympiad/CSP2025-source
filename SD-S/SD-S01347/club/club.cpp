#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
#define PII pair<int,int>
using namespace std;
const int maxN=1e6+10,INF=LONG_LONG_MAX;
vector<int> sum[4],v;
//priority_queue<PII,vector<PII>,greater<PII> >pq;
int _,n,a[maxN][5],ans;
void solve(){
	cin>>n;
	for(int i=1;i<=3;i++) sum[i].clear();
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=-1;
		for(int j=1;j<=3;j++) 
			if(mx<a[i][j])mx=a[i][j],a[i][4]=j;
		sum[a[i][4]].push_back(i);
	}
	v.clear(),ans=0;
	for(int i=1;i<=3;i++){
		for(auto e:sum[i]) ans+=a[e][i];
		if(sum[i].size()>n/2){
			for(auto e:sum[i]){
				int h=INF;
				for(int j=1;j<=3;j++)
					if(i!=j) h=min(a[e][i]-a[e][j],h);
				v.push_back(h);
			}
			sort(v.begin(),v.end());
			for(int j=0;j<sum[i].size()-n/2;j++)ans-=v[j];
		}
	}
	cout<<ans<<endl;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--) solve();
	return 0;
}//Ren5Jie4Di4Ling5%
