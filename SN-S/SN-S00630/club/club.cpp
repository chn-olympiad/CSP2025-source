/*#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100010][4];
queue<pair<int,int>> q0;
queue<pair<int,int>> q1;
int cn0=0,cn1=0,cn2=0,ans=0;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int k=n/2;
		cn0=0,cn1=0,cn2=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int x=-1,xx;
			if(a[i][0]>a[i][1]){
				x=a[i][0];
				xx=0;
				if(x<a[i][2]){
					x=a[i][2];
					xx=2;
				}
			}else{
				x=a[i][1];
				xx=1;
				if(x<a[i][2]){
					x=a[i][2];
					xx=2;
				}
			}
			if(xx==0){
				cn0++;
				if(q0.size()==0||q0[q0.size()].first>=x){
					q0.push({x,i});
				}else{
					while(x>q0.top().first){
						q3.push(q0.top());
						q0.pop();					
					}
					q0.push({x,i});
					while(!q3.empty()){
						q0.push(q3.top());
						q3.pop();
					}
				}
			}else if(xx==1){
				cn1++;
				if(q1.empty()||q1.top().first>=x){
					q1.push({x,i});
				}else{
					while(x>q1.top().first){
						q3.push(q1.top());
						q1.pop();					
					}
					q1.push({x,i});
					while(!q3.empty()){
						q1.push(q3.top());
						q3.pop();
					}
				}
			}else{
				cn2++;
				if(q2.empty()||q2.top().first>=x){
					q2.push({x,i});
				}else{
					while(x>q2.top().first){
						q3.push(q2.top());
						q2.pop();					
					}
					q2.push({x,i});
					while(!q3.empty()){
						q2.push(q3.top());
						q3.pop();
					}
				}
			}
		}
		while(cn0>k){
			cn0--;
			if(a[q0.top().second][1]<a[q0.top().second][2]) {
				q1.push({[q0.top().second][1],[q0.top().second]});
				cn1++;
			}else{
				q2.push({[q0.top().second][2],[q0.top().second]});
				cn2++;	
			}
			q0.pop();
		}
		while(cn1>k){
			cn1--;
			if(cn0<=k&&a[q0.top().second][0]<a[q0.top().second][2]) {
				q0.push({[q1.top().second][0],[q0.top().second]});
				cn0++;
			}else{
				q2.push({[q0.top().second][2],[q0.top().second]});
				cn2++;	
			}
			q1.pop();
		}
		while(cn2>k){
			cn2--;
			if(cn0<=k&&a[q0.top().second][0]<a[q1.top().second][1]) {
				q0.push({[q0.top().second][0],[q0.top().second]});
				cn0++;
			}else{
				q1.push({[q1.top().second][1],[q1.top().second]});
				cn1++;	
			}
			q1.pop();
		}
		while(!q0.empty()){
			ans+=q0.top().first;
			q0.pop();
		}
		while(!q1.empty()){
			ans+=q1.top().first;
			q1.pop();
		}
		while(!q2.empty()){
			ans+=q2.top().first;
			q2.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
} */
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a[100010][3];
		int n;
		cin>>n;
		int k=n/2;
		bool flag1=1,flag2=1;
		stack<int> q,q1;
 	 	for(int i=1;i<=n;i++){
 	 		cin>>a[i][0]>>a[i][1]>>a[i][2];
 	 		if(a[i][1]!=0)flag1=0;
 	 		if(a[i][2]!=0)flag2=0;
 	 		
		}
		int xx,xx2,xx3,xx4;

		if(n==2){
			if(a[1][0]>=a[1][1]){
				if(a[1][0]>=a[1][2]){
					xx=0;
					if(a[1][1]>=a[1][2]){
						xx2=1;
					}else{
						xx2=2;
					}
				}else{
					xx=2;
					xx2=0;
				}
			}else{
				if(a[1][1]>=a[1][2]){
					xx=1;
					if(a[1][0]>=a[1][2]){
						xx2=0;
					}else{
						xx2=2;
					}
				}else{
					xx=2;
					xx2=1;
				}
			}			
			if(a[2][0]>=a[2][1]){
				if(a[2][0]>=a[2][2]){
					xx3=0;
					if(a[2][1]>=a[2][2]){
						xx4=1;
					}else{
						xx4=2;
					}
				}else{
					xx3=2;
					xx4=0;
				}
			}else{
				if(a[2][1]>=a[2][2]){
					xx3=1;
					if(a[2][0]>=a[2][2]){
						xx4=0;
					}else{
						xx4=2;
					}
				}else{
					xx3=2;
					xx4=1;
				}
			}			
			if(xx==xx3){
				cout<<max(a[1][xx]+a[2][xx4],a[1][xx2]+a[2][xx3])<<'\n';
			}else{
				cout<<a[1][xx]+a[2][xx3]<<'\n';
			}
		}
		
		if(flag1==1&&flag2==1){
			for(int i=1;i<=n;i++){
				if(i==1){
					q.push(a[i][0]);
				}
				while(a[i][0]>q.top()){
					q1.push(q.top());
					q.pop();
				}
				q.push(a[i][0]);
				while(!q1.empty()){
					q.push(q1.top());
					q1.pop();
				}
			}
			int sum=0;
			for(int i=1;i<=k;i++){
				sum+=q.top();
				q.pop();
			}
			cout<<sum<<'\n';
		}
		
	}
	
	return 0;
}
