#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
struct node{
	int x1,x2,x3;
}a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q1,q2,q3;
void get_ans(){
	long long ans=0;
	while(!q1.empty()){
		ans+=a[q1.top().second].x1;
		q1.pop();
	}
	while(!q2.empty()){
		ans+=a[q2.top().second].x2;
		q2.pop();
	}
	while(!q3.empty()){
		ans+=a[q3.top().second].x3;
		q3.pop();
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(int i=1;i<=n;i++){
			if(a[i].x1>=max(a[i].x2,a[i].x3)){
				q1.push({a[i].x1-max(a[i].x2,a[i].x3),i});
			}
			else if(a[i].x2>=max(a[i].x1,a[i].x3)){
				q2.push({a[i].x2-max(a[i].x1,a[i].x3),i});
			}
			else{
				q3.push({a[i].x3-max(a[i].x1,a[i].x2),i});
			}
		}
		if(q1.size()<=n/2&&q2.size()<=n/2&&q3.size()<=n/2){
			get_ans();
		}
		else{
			if(q1.size()>n/2){
				while(q1.size()>n/2){
					int t=q1.top().second;
					q1.pop();
					if(a[t].x2>=a[t].x3){
						q2.push({a[t].x2-a[t].x3,t});
					}
					else{
						q3.push({a[t].x3-a[t].x2,t});
					}
				}
			}
			else if(q2.size()>n/2){
				while(q2.size()>n/2){
					int t=q2.top().second;
					q2.pop();
					if(a[t].x1>=a[t].x3){
						q1.push({a[t].x1-a[t].x3,t});
					}
					else{
						q3.push({a[t].x3-a[t].x1,t});
					}
				}
			}
			else{
				while(q3.size()>n/2){
					int t=q3.top().second;
					q3.pop();
					if(a[t].x1>=a[t].x2){
						q1.push({a[t].x1-a[t].x2,t});
					}
					else{
						q2.push({a[t].x2-a[t].x1,t});
					}
				}
			}
			get_ans();
		}
	}
	return 0;
}

