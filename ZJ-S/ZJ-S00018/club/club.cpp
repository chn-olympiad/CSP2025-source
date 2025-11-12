#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void init();void Solve();
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;init();
	cin>>T;
	while(T--) Solve();
	return 0;
}
void init(){
}
int n,a[100005][4],id[100005][4],ans,t;
vector<int> p[4];
bool cmp(int x,int y){
	return a[x][id[x][2]]-a[x][id[x][1]]>a[y][id[y][2]]-a[y][id[y][1]];
}
void Solve(){
	cin>>n;ans=0;
	p[1].clear();p[2].clear();p[3].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			id[i][j]=j;
		}
		if(a[i][id[i][1]]<a[i][id[i][2]]) swap(id[i][1],id[i][2]);
		if(a[i][id[i][2]]<a[i][id[i][3]]) swap(id[i][2],id[i][3]);
		if(a[i][id[i][1]]<a[i][id[i][2]]) swap(id[i][1],id[i][2]);
		p[id[i][1]].push_back(i);
		ans+=a[i][id[i][1]];
	}
	if((int)p[1].size()<=n/2&&(int)p[2].size()<=n/2&&(int)p[3].size()<=n/2){
		cout<<ans<<endl;
		return;
	}
	if((int)p[1].size()>n/2) t=1;
	if((int)p[2].size()>n/2) t=2;
	if((int)p[3].size()>n/2) t=3;
	sort(p[t].begin(),p[t].end(),cmp);
	for(int i=0;i<(int)p[t].size()-n/2;i++){
		int x=p[t][i];
		ans+=a[x][id[x][2]]-a[x][id[x][1]];
	}
	cout<<ans<<endl;
}
