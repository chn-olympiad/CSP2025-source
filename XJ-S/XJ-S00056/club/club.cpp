#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;
ll n,a[114514][10],be[N][N][N],d,nc[10],ans=LLONG_MIN;
void dfs(int now,int c,ll w){
	if(w<=be[nc[1]][nc[2]][nc[3]]) return;
	be[nc[1]][nc[2]][nc[3]]=max(be[nc[1]][nc[2]][nc[3]],w);
	if(now==n){
		ans=max(ans,w);
		return;
	}
	if(nc[1]<d){
		nc[1]+=1;
		dfs(now+1,1,w+a[now+1][1]);
		nc[1]-=1;
	}
	if(nc[2]<d){
		nc[2]+=1;
		dfs(now+1,2,w+a[now+1][2]);
		nc[2]-=1;
	}
	if(nc[3]<d){
		nc[3]+=1;
		dfs(now+1,3,w+a[now+1][3]);
		nc[3]-=1;
	}
}
void dfs1(int now,int c,ll w){
	if(w<=be[nc[1]][nc[2]][nc[3]]) return;
	be[nc[1]][nc[2]][nc[3]]=max(be[nc[1]][nc[2]][nc[3]],w);
	if(now==n){
		ans=max(ans,w);
		return;
	}
	if(nc[1]<d){
		nc[1]+=1;
		dfs1(now+1,1,w+a[now+1][1]);
		nc[1]-=1;
	}
	if(nc[2]<d){
		nc[2]+=1;
		dfs1(now+1,2,w+a[now+1][2]);
		nc[2]-=1;
	}
}
void dfs3(int now,int c,ll w){
	if(now==n){
		ans=max(ans,w);
		return;
	}
	if(nc[1]<d){
		nc[1]+=1;
		dfs3(now+1,1,w+a[now+1][1]);
		nc[1]-=1;
	}
	if(nc[2]<d){
		nc[2]+=1;
		dfs3(now+1,2,w+a[now+1][2]);
		nc[2]-=1;
	}
}
void solve(){
	cin>>n;
	d=n/2;
	nc[1]=nc[2]=nc[3]=0;
	ans=LLONG_MIN;
	bool f=1,f1=1;
	memset(be,-1,sizeof(be));
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]||a[i][3]) f=0;
		if(a[i][3]) f=0;
	}
	if(f==1){
		vector<int> e;
		for(int i=1,c1,c2,c3;i<=n;i++){
			e.push_back(a[i][1]);
		}
		sort(e.begin(),e.end());
		ans=0;
		for(int i=d+1;i<=n;i++){
			ans+=e[i-1];
		}
		cout<<ans<<'\n';
		return;
	}
	if(f1==1){
		dfs1(0,0,0);
	}else if(n>200&&f1==1){
		dfs3(0,0,0);
	}else{
		dfs(0,0,0);	
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve(); 
	return 0;
} 
