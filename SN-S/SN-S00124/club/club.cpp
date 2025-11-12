#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+15;
int T,n,a[maxn][3],ans,d[maxn];
vector<int> v[3];
bool cmp(int x,int y){
	return d[x]<d[y];
}
void sve(int id){
	for(int x:v[id]){
		d[x]=1e9;
		for(int _=0;_<=2;_++){
			if(_!=id) d[x]=min(d[x],a[x][id]-a[x][_]);
		}
	}
	sort(v[id].begin(),v[id].end(),cmp);
	int x=v[id].size()-n/2;
	for(int i=0;i<x;i++) ans-=d[v[id][i]];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		v[0].clear();
		v[1].clear();
		v[2].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max(max(a[i][0],a[i][1]),a[i][2]);
			if(mx==a[i][0]) v[0].push_back(i);
			else if(mx==a[i][1]) v[1].push_back(i);
			else v[2].push_back(i);
			ans+=mx;
		}
		if((int)v[0].size()>n/2) sve(0);
		else if((int)v[1].size()>n/2) sve(1);
		else if((int)v[2].size()>n/2) sve(2);
		cout<<ans<<'\n';
	}
	return 0;
}
