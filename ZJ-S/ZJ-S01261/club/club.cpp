#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
const int N=1e5+5;
int _,n,a[N][3],ans;
bool vis[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>_;_--;memset(vis,ans=0,sizeof vis)){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
		priority_queue<pii>q[3];
		for(int i=1;i<=n;++i){
			int mx=max({a[i][0],a[i][1],a[i][2]}),t;
			q[mx==a[i][0]?0:(mx==a[i][1]?1:2)].push({-mx,i});
		}
		for(;max({q[0].size(),q[1].size(),q[2].size()})>n/2;){
			for(;q[0].size()>n/2;){
				int k=q[0].size()-n/2;
				vector<int>v;
				for(;q[0].size();q[0].pop())v.push_back(q[0].top().se);
				sort(v.begin(),v.end(),[](int x,int y){return a[x][0]-max(a[x][1],a[x][2])<a[y][0]-max(a[y][1],a[y][2]);});
				for(auto i:v){
					if(!k)break;
					if(a[i][1]==a[i][2]){
						if(!vis[i][1])q[1].push({-a[i][1],i}),vis[i][0]=1,k--;
						else if(!vis[i][2])q[2].push({-a[i][2],i}),vis[i][0]=1,k--;
					}else if(a[i][1]>a[i][2]&&!vis[i][1])q[1].push({-a[i][1],i}),vis[i][0]=1,k--;
					else if(!vis[i][2])q[2].push({-a[i][2],i}),vis[i][0]=1,k--;
				}for(auto i:v)if(!vis[i][0])q[0].push({-a[i][0],i});
			}for(;q[1].size()>n/2;){
				int k=q[1].size()-n/2;
				vector<int>v;
				for(;q[1].size();q[1].pop())v.push_back(q[1].top().se);
				sort(v.begin(),v.end(),[](int x,int y){return a[x][1]-max(a[x][0],a[x][2])<a[y][1]-max(a[y][0],a[y][2]);});
				for(auto i:v){
					if(!k)break;
					if(a[i][2]==a[i][0]){
						if(!vis[i][2])q[2].push({-a[i][2],i}),vis[i][1]=1,k--;
						else if(!vis[i][0])q[0].push({-a[i][0],i}),vis[i][1]=1,k--;
					}else if(a[i][0]>a[i][2]&&!vis[i][0])q[0].push({-a[i][0],i}),vis[i][1]=1,k--;
					else if(!vis[i][2])q[2].push({-a[i][2],i}),vis[i][1]=1,k--;
				}for(auto i:v)if(!vis[i][1])q[1].push({-a[i][1],i});
			}for(;q[2].size()>n/2;){
				int k=q[2].size()-n/2;
				vector<int>v;
				for(;q[2].size();q[2].pop())v.push_back(q[2].top().se);
				sort(v.begin(),v.end(),[](int x,int y){return a[x][2]-max(a[x][1],a[x][0])<a[y][2]-max(a[y][1],a[y][0]);});
				for(auto i:v){
					if(!k)break;
					if(a[i][1]==a[i][0]){
						if(!vis[i][1])q[1].push({-a[i][1],i}),vis[i][2]=1,k--;
						else if(!vis[i][0])q[0].push({-a[i][0],i}),vis[i][2]=1,k--;
					}else if(a[i][1]>a[i][0]&&!vis[i][1])q[1].push({-a[i][1],i}),vis[i][2]=1,k--;
					else if(!vis[i][0])q[0].push({-a[i][0],i}),vis[i][2]=1,k--;
				}for(auto i:v)if(!vis[i][2])q[2].push({-a[i][2],i});
			}
		}for(int i=0;i<3;++i)for(;q[i].size();q[i].pop())ans-=q[i].top().fi;
		cout<<ans<<'\n';
	}return 0;
}// It is for my first time that I write so long in T1.I'm to lazy to make it shorter.That's OK.