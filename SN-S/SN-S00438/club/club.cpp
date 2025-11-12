//¶ÎÑÅçÍ SN-S00438 ¸¨ÂÖÖÐÑ§
#include<bits/stdc++.h>
using namespace std;
long long n,a[100002][4],ans,t;
priority_queue<long long>q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int nc=min(a[i][0],min(a[i][1],a[i][2])),na=max(a[i][0],max(a[i][1],a[i][2])),nb=a[i][0]+a[i][1]+a[i][2]-na-nc;
			a[i][3]=na-nb; 
			ans+=na;
			if(na==a[i][0]){
				q[0].push(-a[i][3]);
			}
			if(na==a[i][1]){
				q[1].push(-a[i][3]);
			}
			if(na==a[i][2]){
				q[2].push(-a[i][3]);
			}
		}
		if(q[0].size()>n/2){
			while(q[0].size()>n/2){
				ans+=q[0].top();
				q[0].pop();
			}
		}
		if(q[1].size()>n/2){
			while(q[1].size()>n/2){
				ans+=q[1].top();
				q[1].pop();
			}
		}
		if(q[2].size()>n/2){
			while(q[2].size()>n/2){
				ans+=q[2].top();
				q[2].pop();
			}
		}
		cout<<ans<<"\n";	
		ans=0;
		for(int i=0;i<3;i++){
			priority_queue<long long>w;
			swap(q[i],w); 
		}
	}
	return 0;
}
