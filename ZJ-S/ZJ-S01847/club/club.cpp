#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,cnt1,cnt2,cnt3;
bool vis[N];
struct node{int x,y,z;}a[N];
vector <int> vec[5];
struct Node{
	int x,y,z,w;
	friend bool operator < (Node x,Node y){return x.x>y.x;}
};
priority_queue <Node> q;
bool work1(int x){
	if(x==1) return cnt1==n/2;
	if(x==2) return cnt2==n/2;
	if(x==3) return cnt3==n/2;
}
void work2(int x){
	if(x==1) cnt1++;
	if(x==2) cnt2++;
	if(x==3) cnt3++;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);cnt1=cnt2=cnt3=ans=0;
		while(!q.empty()) q.pop();
		for(int i=1;i<=3;i++) vec[i].clear();
		int m=n/2;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			int maxx=max({a[i].x,a[i].y,a[i].z});ans+=maxx;
			if(a[i].x==maxx) cnt1++,vec[1].push_back(i);
			else if(a[i].y==maxx) cnt2++,vec[2].push_back(i);
			else cnt3++,vec[3].push_back(i);
		}
		if(cnt1<=m&&cnt2<=m&&cnt3<=m){printf("%d\n",ans);continue;}
		if(cnt1>m){
			for(int i=0;i<vec[1].size();i++){
				int id=vec[1][i];
				int k1=a[id].x-a[id].y,k2=a[id].x-a[id].z;
				if(k1<k2) q.push({k1,a[id].x,2,id});
				else q.push({k2,a[id].x,3,id});
			}
			while(cnt1>m){
				Node u=q.top();q.pop();
				if(vis[u.w]) continue;
				if(work1(u.z)) continue;
				vis[u.w]=1;
				cnt1--;work2(u.z);
				ans-=u.x;
			}
	    	printf("%d\n",ans);
	    	continue;
		}
		if(cnt2>m){
			for(int i=0;i<vec[2].size();i++){
				int id=vec[2][i];
				int k1=a[id].y-a[id].x,k2=a[id].y-a[id].z;
				if(k1<k2) q.push({k1,a[id].x,1,id});
				else q.push({k2,a[id].x,3,id});
			}
			while(cnt2>m){
				Node u=q.top();q.pop();
				if(vis[u.w]) continue;
				if(work1(u.z)) continue;
				vis[u.w]=1;
				cnt2--;work2(u.z);
				ans-=u.x;
			}
	    	printf("%d\n",ans);
	    	continue;
		}
		for(int i=0;i<vec[3].size();i++){
			int id=vec[3][i];
			int k1=a[id].z-a[id].x,k2=a[id].z-a[id].y;
		    if(k1<k2) q.push({k1,a[id].x,1,id});
			else q.push({k2,a[id].x,2,id});
		}
		while(cnt3>m){
			Node u=q.top();q.pop();
			if(vis[u.w]) continue;
			if(work1(u.z)) continue;
			vis[u.w]=1;
			cnt3--;work2(u.z);
			ans-=u.x;
		}
		printf("%d\n",ans);
	}
	return 0;
}

