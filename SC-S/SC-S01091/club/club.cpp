#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T,p[N];
struct node{
	int w,x,y;
	bool operator<(const node &t)const{
		return w<t.w;
	}
	bool operator>(const node &t)const{
		return w>t.w;
	}
}a[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		priority_queue<node> q[4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].w;
				a[i][j].y=j;
			}
			sort(a[i]+1,a[i]+4,greater<node>());
		}
		for(int i=1;i<=n;i++){
			if(q[a[i][1].y].size()<n/2){
				ans+=a[i][1].w;
				q[a[i][1].y].push({a[i][2].w-a[i][1].w,i,2});
			}
			else{
				node t=q[a[i][1].y].top();
				if(a[i][2].w>a[i][1].w+t.w) ans+=a[i][2].w,q[a[i][2].y].push({a[i][3].w-a[i][2].w,i,3});
				else{
					ans+=a[i][1].w+t.w;
					q[a[i][1].y].pop();
					q[a[i][1].y].push({a[i][2].w-a[i][1].w,i,2});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}