#include<bits/stdc++.h>
using namespace std;
#define maxn 100011
#define max(a,b) ((a)>(b)?(a):(b))
void file(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int ans,n;
int a[maxn][4];
struct AdjustNode{
	int idx,val;
	bool operator < (const AdjustNode &ano)const{
		return val>ano.val;
	}
}b[maxn][4];
int pos[4];
vector<int> id[4];
void init(){
	for(int i=1;i<=3;++i){
		id[i].clear();
		pos[i]=0;
	}
}
bool cmp(int x,int y){
	return b[x][1].val-b[x][2].val<b[y][1].val-b[y][2].val;
}
void solve(){
	int adj=0;
	for(int i=1;i<=3;++i){
		if(id[i].size()*2>n){
			adj=i;
		}
	}
	if(adj){
		sort(id[adj].begin(),id[adj].end(),cmp);
		while(id[adj].size()-pos[adj]>n/2){
			int now=id[adj][pos[adj]];
			id[b[now][2].idx].push_back(now);
			++pos[adj];
		}
	}
	ans=0;
	for(int i=1;i<=3;++i){
		for(int j=pos[i];j<id[i].size();++j){
			ans+=a[id[i][j]][i];
		}
	}
}
int main(){
	file();
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
				b[i][j].idx=j,b[i][j].val=a[i][j];
			}
			sort(b[i]+1,b[i]+3+1);
			id[b[i][1].idx].push_back(i);
		}
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
