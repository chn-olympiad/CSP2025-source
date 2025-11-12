#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
#define pII pair<int,int>
using namespace std;
const int maxn=1e5+10;
pII a[maxn][5];
int pos[maxn];
priority_queue<pII,vector<pII>,greater<pII> > q[4];
bool cmp(pII a,pII b){
	if(a.first!=b.first) return a.first>b.first;
	return a.second<b.second;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		f(i,1,n){pos[i]=1;
			f(j,1,3) cin>>a[i][j].first,a[i][j].second=j;
			sort(a[i]+1,a[i]+4,cmp);
		}
		f(i,1,n){
			if(q[a[i][1].second].size()<n/2) q[a[i][1].second].push({a[i][1].first-a[i][2].first,i});
			else{
				if(q[a[i][1].second].top().first<a[i][1].first-a[i][2].first){
					pII tmp=q[a[i][1].second].top();
					q[a[i][1].second].pop();q[a[i][1].second].push({a[i][1].first-a[i][2].first,i});
					pos[tmp.second]++;
					if(pos[tmp.second]<=2) q[a[tmp.second][pos[tmp.second]].second].push({a[tmp.second][pos[tmp.second]].first-a[tmp.second][pos[tmp.second]+1].first,tmp.second});
					else q[a[tmp.second][pos[tmp.second]].second].push({1000000000,tmp.second});
				}else{
					pos[i]++;
					q[a[i][pos[i]].second].push({a[i][pos[i]].first-a[i][pos[i]+1].first,i});
				}
			}
		}int ans=0;
		f(i,1,3) while(q[i].size()){int wh=q[i].top().second;
			ans+=a[wh][pos[wh]].first;q[i].pop();
		}cout<<ans<<'\n';
	}
	return 0;
} 
