#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,maxn,s;
struct node{
	int x,y,z;
}a[N];
bool cmp(node sx,node sy){
	return sx.x>sy.x;
}
void dfs(int id,int sx,int sy,int sz,int nx,int ny,int nz){
	if(id==n){
		maxn=max(sx+sy+sz,maxn);
		return ;
	}
	if(nx<n/2) dfs(id+1,sx+a[id+1].x,sy,sz,nx+1,ny,nz);
	if(ny<n/2) dfs(id+1,sx,sy+a[id+1].y,sz,nx,ny+1,nz);
	if(nz<n/2) dfs(id+1,sx,sy,sz+a[id+1].z,nx,ny,nz+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z==0&&a[i].y==0) s++;
		}
		if(s==n){
			int s=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				s+=a[i].x;
			}
			cout<<s<<'\n';
			continue;
		}
		dfs(0,0,0,0,0,0,0);
		cout<<maxn<<'\n';
	}
	return 0;
}
