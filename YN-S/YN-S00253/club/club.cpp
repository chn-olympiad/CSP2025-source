#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
int t;
int n;
struct node{
	int x,y,z;
}a[N];
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
void cl(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		cl();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==a[i].y&&a[i].x==a[i].z){
				ans+=a[i].x;
				continue;
			}
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				int mn=min(a[i].x-a[i].y,a[i].x-a[i].z);
				q1.push(mn);
				ans+=a[i].x;
				continue;
			}
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				int mn=min(a[i].y-a[i].x,a[i].y-a[i].z);
				q2.push(mn);
				ans+=a[i].y;
				continue;
			}
			if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
				int mn=min(a[i].z-a[i].y,a[i].z-a[i].x);
				q3.push(mn);
				ans+=a[i].z;
				continue;
			}
		}
		while(q1.size()>n/2){
			ans-=q1.top();q1.pop();
		}
		while(q2.size()>n/2){
			ans-=q2.top();q2.pop();
		}
		while(q3.size()>n/2){
			ans-=q3.top();q3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}