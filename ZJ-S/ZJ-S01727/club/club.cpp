#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
int n;
int a[maxn][5];
vector<int> p[5];
void mymain(){
	cin>>n;
	for(int i=1;i<=3;i++) p[i].clear();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		int mx=max(max(a[i][1],a[i][2]),a[i][3]);
		for(int j=1;j<=3;j++){
			if(mx==a[i][j]){
				p[j].push_back(i),ans+=a[i][j];
				break;
			}
		}
	}
	int m=n/2;
	if(p[1].size()<=m&&p[2].size()<=m&&p[3].size()<=m) return cout<<ans<<'\n',void();
	if(p[1].size()>m){
		sort(p[1].begin(),p[1].end(),[](int x,int y){return a[x][1]-max(a[x][2],a[x][3])<a[y][1]-max(a[y][2],a[y][3]);});
		for(int i=0;i<p[1].size()-m;i++){
			int x=p[1][i];
			ans-=a[x][1],ans+=max(a[x][2],a[x][3]);
		}	
		cout<<ans<<'\n';
		return;
	}
	if(p[2].size()>m){
		sort(p[2].begin(),p[2].end(),[](int x,int y){return a[x][2]-max(a[x][1],a[x][3])<a[y][2]-max(a[y][1],a[y][3]);});
		for(int i=0;i<p[2].size()-m;i++){
			int x=p[2][i];
			ans-=a[x][2],ans+=max(a[x][1],a[x][3]);
		}	
		cout<<ans<<'\n';
		return;
	}  
	if(p[3].size()>m){
		sort(p[3].begin(),p[3].end(),[](int x,int y){return a[x][3]-max(a[x][1],a[x][2])<a[y][3]-max(a[y][1],a[y][2]);});
		for(int i=0;i<p[3].size()-m;i++){
			int x=p[3][i];
			ans-=a[x][3],ans+=max(a[x][1],a[x][2]);
		}	
		cout<<ans<<'\n';
		return;
	}  
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int _; cin>>_;
	while(_--) mymain();
	return 0;
}