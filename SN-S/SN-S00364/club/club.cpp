#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100001],a2[100001],a3[100001],cnt;
struct node{
	int id,val;
};
bool operator<(node x,node y){
	return x.val>y.val;
}
priority_queue<node>q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				if(q1.size()==n/2){
					if(a1[i]+a2[q1.top().id]>=a1[i]+a3[q1.top().id]&&
					a1[i]+a2[q1.top().id]>=a2[i]+q1.top().val&&
					a1[i]+a2[q1.top().id]>=a3[i]+q1.top().val){
						q2.push({q1.top().id,a2[q1.top().id]});
						q1.pop();
						q1.push({i,a1[i]});
					}
					else if(a1[i]+a3[q1.top().id]>=a2[i]+q1.top().val&&
					a1[i]+a3[q1.top().id]>=a3[i]+q1.top().val){
						q3.push({q1.top().id,a3[q1.top().id]});
						q1.pop();
						q1.push({i,a1[i]});
					}
					else if(a2[i]+q1.top().val>=a3[i]+q1.top().val){
						q2.push({i,a2[i]});
					}
					else{
						q3.push({i,a3[i]});
					}
				}
				else{
					q1.push({i,a1[i]});
				}
			}
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				if(q2.size()==n/2){
					if(a2[i]+a1[q2.top().id]>=a2[i]+a3[q2.top().id]&&
					a2[i]+a1[q2.top().id]>=a1[i]+q2.top().val&&
					a2[i]+a1[q2.top().id]>=a3[i]+q2.top().val){
						q1.push({q2.top().id,a1[q2.top().id]});
						q2.pop();
						q2.push({i,a2[i]});
					}
					else if(a2[i]+a3[q2.top().id]>=a1[i]+q2.top().val&&
					a2[i]+a3[q2.top().id]>=a3[i]+q2.top().val){
						q3.push({q2.top().id,a3[q2.top().id]});
						q2.pop();
						q2.push({i,a2[i]});
					}
					else if(a1[i]+q2.top().val>=a3[i]+q2.top().val){
						q1.push({i,a1[i]});
					}
					else{
						q3.push({i,a3[i]});
					}
				}
				else{
					q2.push({i,a2[i]});
				}
			}
			else if(a3[i]>=a1[i]&&a3[i]>=a2[i]){
				if(q3.size()==n/2){
					if(a3[i]+a1[q3.top().id]>=a3[i]+a2[q3.top().id]&&
					a3[i]+a1[q3.top().id]>=a1[i]+q3.top().val&&
					a3[i]+a1[q3.top().id]>=a2[i]+q3.top().val){
						q1.push({q3.top().id,a1[q3.top().id]});
						q3.pop();
						q3.push({i,a3[i]});
					}
					else if(a3[i]+a2[q3.top().id]>=a1[i]+q3.top().val&&
					a3[i]+a2[q3.top().id]>=a2[i]+q3.top().val){
						q2.push({q3.top().id,a2[q3.top().id]});
						q3.pop();
						q3.push({i,a3[i]});
					}
					else if(a1[i]+q3.top().val>=a2[i]+q3.top().val){
						q1.push({i,a1[i]});
					}
					else{
						q2.push({i,a2[i]});
					}
				}
				else{
					q3.push({i,a3[i]});
				}
			}
		}
		while(!q1.empty()){
			cnt+=q1.top().val;
			q1.pop();
		}
		while(!q2.empty()){
			cnt+=q2.top().val;
			q2.pop();
		}
		while(!q3.empty()){
			cnt+=q3.top().val;
			q3.pop();
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
