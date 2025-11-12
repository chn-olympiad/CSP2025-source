#include<bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int T;
int n;
int ans=0;
struct node{
	int id;
	int x;
	int y;
	int z;
}a[Maxn];
void dfs(int depth,int cnt,int u,int v,int w){
	if(u>n/2) return;
	if(v>n/2) return;
	if(w>n/2) return;
	if(depth==n+1){
		ans=max(ans,cnt);
		return;
	}
	dfs(depth+1,cnt+a[depth].x,u+1,v,w);
	dfs(depth+1,cnt+a[depth].y,u,v+1,w);
	dfs(depth+1,cnt+a[depth].z,u,v,w+1);
}
bool cmp(node u,node v){
	return u.x>v.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		bool special_a=1;
		ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			if(a[i].y || a[i].z) special_a=0;
		}
		if(special_a){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
