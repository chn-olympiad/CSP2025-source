#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
struct node{
	int x,y,z;
};
node a[100010];
inline bool cmp1(node x,node y){
	if(x.x!=0) return x.x>y.x;
	if(x.y!=0) return x.y>y.y;
	return x.z>y.z;
}
inline dfsxy(int i,int a1,int tx,int ty){
	if(i==n+1) return tx+ty;
	if(a1==n/2){
		for(;i<=n;i++){
			ty+=a[i].y;
		}
		return tx+ty;
	}
	if(i-a1==n/2){
		for(;i<=n;i++){
			tx+=a[i].x;
		}
		return tx+ty;
	}
	int ans=max(dfsxy(i+1,a1+1,tx+a[i].x,ty),dfsxy(i+1,a1,tx,ty+a[i].y));
	return ans;
}
inline dfsxz(int i,int a1,int tx,int ty){
	if(i==n+1) return tx+ty;
	if(a1==n/2){
		for(;i<=n;i++){
			ty+=a[i].z;
		}
		return tx+ty;
	}
	if(i-a1==n/2){
		for(;i<=n;i++){
			tx+=a[i].x;
		}
		return tx+ty;
	}
	int ans=max(dfsxz(i+1,a1+1,tx+a[i].x,ty),dfsxz(i+1,a1,tx,ty+a[i].z));
	return ans;
}
inline dfsyz(int i,int a1,int tx,int ty){
	if(i==n+1) return tx+ty; 
	if(a1==n/2){
		for(;i<=n;i++){
			ty+=a[i].y;
		}
		return tx+ty;
	}
	if(i-a1==n/2){
		for(;i<=n;i++){
			tx+=a[i].z;
		}
		return tx+ty;
	}
	int ans=max(dfsyz(i+1,a1+1,tx+a[i].z,ty),dfsyz(i+1,a1,tx,ty+a[i].y));
	return ans;
}
inline dfs2(int i,int a1,int a2,int a3,int tx,int ty,int tz){
	if(i==n+1) return tx+ty+tz;
	if(a1==n/2){
		return tx+ty+tz+dfsyz(i,a2,0,0);
	}
	if(a2==n/2){
		return tx+ty+tz+dfsxz(i,a1,0,0);
	}
	if(a3==n/2){
		return tx+ty+tz+dfsxy(i,a1,0,0);
	}
	int ans=max(dfs2(i+1,a1+1,a2,a3,tx+a[i].x,ty,tz),max(dfs2(i+1,a1,a2+1,a3,tx,ty+a[i].y,tz),dfs2(i+1,a1,a2,a3+1,tx,ty,tz+a[i].z)));
	return ans;
}
inline void solve(){
	bool f1,f2,f3,f4,f5,f6;
	f1=f2=f3=f4=f5=f6=1;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z; 
		f1=(f1&&a[i].x==a[i].y&&a[i].x==0); f4=(f4&&a[i].x==0);
		f2=(f2&&a[i].x==a[i].z&&a[i].x==0); f5=(f5&&a[i].y==0);
		f3=(f3&&a[i].y==a[i].z&&a[i].y==0); f6=(f6&&a[i].z==0);
	}
	if(f1||f2||f3){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++) ans+=(a[i].x!=0 ? a[i].x : (a[i].y!=0 ? a[i].y : a[i].z));
	} else if(f4){
		ans=dfsyz(1,0,0,0);
	} else if(f5){
		ans=dfsxz(1,0,0,0);
	} else if(f6){
		ans=dfsxy(1,0,0,0);
	} else {
		ans=dfs2(1,0,0,0,0,0,0);
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
