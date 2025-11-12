#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	int x,y,z;
} a[111111];

int n,mx=-1,x,y,z;

void dfs(int now,int sum){
	if(now==n+1){
		mx=max(mx,sum);
		return;
	}
	if(x<n/2){
		x++;
		dfs(now+1,sum+a[now].x);
		x--;
	}
	if(y<n/2){
		y++;
		dfs(now+1,sum+a[now].y);
		y--;
	}
	if(z<n/2){
		z++;
		dfs(now+1,sum+a[now].z);
		z--;
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;         
	cin>>T;
	while(T--) {
		memset(a,0,sizeof a);
		mx=-1,x=y=z=0; 
		cin>>n;        
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0);
		cout<<mx<<'\n';
	}              
	return 0;
}
//struct node {
//	int x,y,z;
//	bool fg;
//} a[111111];
//bool cmp(node q,node p) {
//	if(q.x!=p.x) return q.x>p.x;
//	if(q.y!=p.y) return q.y<p.y;
//	if(q.z!=p.z) return q.z<p.z;
//}
//bool cmp1(node q,node p) {
//	if(q.y!=p.y) return q.y>p.y;
//	if(q.x!=p.x) return q.x<p.x;
//	if(q.z!=p.z) return q.z<p.z;
//}
//bool cmp2(node q,node p) {
//	if(q.z!=p.z) return q.z>p.z;
//	if(q.x!=p.x) return q.x<p.x;
//	if(q.y!=p.y) return q.y<p.y;
//}
//int main() {
//	int T;
//	cin>>T;
//	while(T--) {
//		memset(a,0,sizeof a);
//		int n,k=1,sum=0,cnt=0;
//		cin>>n;
//		for(int i=1; i<=n; i++) {
//			cin>>a[i].x>>a[i].y>>a[i].z;
//			a[i].fg=0;
//		}
//		sort(a+1,a+1+n,cmp);
//		while(cnt<n/2&&k<=n) {
//			if(a[k].fg==0&&a[k].x>a[k].z&&a[k].x>a[k].y) {
//				sum+=a[k].x;
//				a[k].fg=1;
//				cnt++;
//			}
//			k++;
//		}
//		k=1,cnt=0;
//		sort(a+1,a+1+n,cmp1);
//		while(cnt<n/2&&k<=n) {
//			if(a[k].fg==0&&a[k].y>a[k].z&&a[k].y>a[k].z) {
//				sum+=a[k].y;
//				a[k].fg=1;
//				cnt++;
//			}
//			k++;
//		}
//		k=1,cnt=0;
//		sort(a+1,a+1+n,cmp2);
//		while(cnt<n/2&&k<=n) {
//			if(a[k].fg==0&&a[k].z>a[k].x&&a[k].z>a[k].x) {
//				sum+=a[k].z;
//				a[k].fg=1;
//				cnt++;
//			}
//			k++;
//		}
//		cout<<sum<<'\n';
//	}
//}
