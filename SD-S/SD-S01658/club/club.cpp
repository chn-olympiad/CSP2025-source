#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],cnt[4],ans,change[N]; 
int maxx(int x){
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])return 1;
	if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3])return 2;
	return 3;
}
vector<int> e[4];
bool cmp(int x,int y){
	return change[x]<=change[y];
}
void solve(int u){
	sort(e[u].begin(),e[u].end(),cmp);
	int k=cnt[u]-n/2;
	for(int i=0;i<k;++i){
		ans-=change[e[u][i]];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--){
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int f=maxx(i),val=a[i][f];
			cnt[f]++;ans+=val;
			e[f].push_back(i);
			a[i][f]=-N;
			change[i]=val-a[i][maxx(i)];
			a[i][f]=val;
		}
		if(cnt[1]>n/2)solve(1);
		if(cnt[2]>n/2)solve(2);
		if(cnt[3]>n/2)solve(3);
		cout<<ans<<"\n";
		e[1].clear();e[2].clear();e[3].clear();
	}
	return 0;
} 
