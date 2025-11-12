#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,k=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) k=k*10+(c-'0'),c=getchar();
	return f*k;
}
const int N=1e5+10;
int t,n,a[N][4];
struct node{
	int w,id,vis1,vis2,vis3;
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};priority_queue<node>q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) a[i][j]=read();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				q1.push({a[i][1]-max(a[i][2],a[i][3]),i,1,0,0});
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				q2.push({a[i][2]-max(a[i][1],a[i][3]),i,0,1,0});
			}else{
				q3.push({a[i][3]-max(a[i][1],a[i][2]),i,0,0,1});
			}
		}
		while(1){
			if(q1.size()<=n/2&&q2.size()<=n/2&&q3.size()<=n/2) break;
			if(q1.size()>n/2){
				while(q1.size()>n/2){
					node t=q1.top();q1.pop();
					if(t.vis2&&t.vis3) continue;
					if(t.w==abs(a[t.id][1]-a[t.id][2])&&t.vis2==0){
						q2.push({abs(a[t.id][2]-a[t.id][3]),t.id,1,1,0});
					}else{
						q3.push({abs(a[t.id][2]-a[t.id][3]),t.id,1,0,1});
					}
				}
			}
			if(q2.size()>n/2){
				while(q2.size()>n/2){
					node t=q2.top();q2.pop();
					if(t.vis1&&t.vis3) continue;
					if(t.w==abs(a[t.id][2]-a[t.id][1])&&t.vis1==0){
						q1.push({abs(a[t.id][3]-a[t.id][1]),t.id,1,1,0});
					}else{
						q3.push({abs(a[t.id][3]-a[t.id][1]),t.id,0,1,1});
					}
				}
			}
			if(q3.size()>n/2){
				while(q3.size()>n/2){
					node t=q3.top();q3.pop();
					if(t.vis1&&t.vis2) continue;
					if(t.w==abs(a[t.id][3]-a[t.id][1])&&t.vis1==0){
						q1.push({abs(a[t.id][3]-a[t.id][2]),t.id,1,0,1});
					}else{
						q2.push({abs(a[t.id][3]-a[t.id][2]),t.id,0,1,1});
					}
				}
			}
		}
		int ans=0;
		while(q1.size()){
			node t=q1.top();q1.pop();ans+=a[t.id][1];
		}
		while(q2.size()){
			node t=q2.top();q2.pop();ans+=a[t.id][2];
		}
		while(q3.size()){
			node t=q3.top();q3.pop();ans+=a[t.id][3];
		}
		cout<<ans<<"\n";
	}
	return 0;
}