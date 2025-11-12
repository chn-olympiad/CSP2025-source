#include<bits/stdc++.h>
using namespace std;
const int N=1e5+17;
int t,n;
struct node{
	int x,y,z;
}a[N][10];
int cnt,bu[10],ans;
bool cmp(node u,node v){
	return u.x>v.x;
}
priority_queue<int> q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bu[1]=bu[2]=bu[3]=0;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].y=1;
			a[i][2].y=2;
			a[i][3].y=3;
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			bu[a[i][1].y]++;
			q[a[i][1].y].push(a[i][2].x-a[i][1].x);
			ans+=a[i][1].x;
		}
		if(bu[1]>n/2){
			while(q[1].size()>n/2){
				int x=q[1].top();
				q[1].pop();
				ans+=x;
			}
		}
		else if(bu[2]>n/2){
			while(q[2].size()>n/2){
				int x=q[2].top();
				q[2].pop();
				ans+=x;
			}
		}
		else if(bu[3]>n/2){
			while(q[3].size()>n/2){
				int x=q[3].top();
				q[3].pop();
				ans+=x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;		
}