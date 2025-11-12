#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int t,n,cnt;
priority_queue <int> q1,q2,q3;
struct Node{
	int x,y,z,flag=0;
}a[100004];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int maxx=max(a[i].x,max(a[i].y,a[i].z));
			if(maxx==a[i].x){
				q1.push(-maxx);
			}
			else if(maxx==a[i].y){
				q2.push(-maxx);
			}
			else{
				q3.push(-maxx);
			}
			if(q1.size()>n/2){
				q1.pop();
			}
			if(q2.size()>n/2){
				q2.pop();
			}
			if(q3.size()>n/2){
				q3.pop();
			}
		}
		while(!q1.empty()){
			cnt=cnt+q1.top();
			q1.pop();
		}
		while(!q2.empty()){
			cnt=cnt+q2.top();
			q2.pop();
		}
		while(!q3.empty()){
			cnt=cnt+q3.top();
			q3.pop();
		}
		cout<<-1*cnt<<endl;
	}
	return 0;
}
