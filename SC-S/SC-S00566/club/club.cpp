#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,a[N][4],id[N][4],cnt[4];
void solve(int tid){
	ans=0,memset(cnt,0,sizeof cnt);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=3;k++){
			cin>>a[i][k];
			id[i][k]=k;
		}
		sort(id[i]+1,id[i]+4,[&](int x,int y){ return a[i][x]<a[i][y]; });
		cnt[id[i][3]]++,ans+=a[i][id[i][3]];
	}
	int p=0;
	for(int k=1;k<=3;k++){
		if(cnt[k]>n/2) p=k;
	}
	if(!p){
		cout<<ans<<"\n";
		return ;
	}
	vector<int> dt;
	for(int i=1;i<=n;i++){
		if(id[i][3]==p){
			int mx=0;
			for(int k=1;k<=3;k++){
				if(k!=p) mx=max(mx,a[i][k]);
			}
			dt.push_back(a[i][p]-mx);
		}
	}
	sort(dt.begin(),dt.end());
	for(int i=0;i<cnt[p]-n/2;i++) ans-=dt[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++) solve(i);
}