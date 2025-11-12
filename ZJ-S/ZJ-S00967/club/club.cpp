#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N][4];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1,q2,q3;

void turn(int x,int p){
	if(p==1){
		int f2=a[x][2],f3=a[x][3];
		if(f2>=f3){
			q2.push({f2,x});
			if(q2.size()>n/2){
				q3.push(q2.top());
				q2.pop();
			}
		}else{
			q3.push({f3,x});
			if(q3.size()>n/2){
				q2.push(q3.top());
				q3.pop();
			}
		}
	}
	if(p==2){
		int f1=a[x][1],f3=a[x][3];
		if(f1>=f3){
			q1.push({f1,x});
			if(q1.size()>n/2){
				q3.push(q1.top());
				q1.pop();
			}
		}else{
			q3.push({f3,x});
			if(q3.size()>n/2){
				q1.push(q3.top());
				q3.pop();
			}
		}
	}
	if(p==3){
		int f2=a[x][2],f1=a[x][1];
		if(f2>=f1){
			q2.push({f2,x});
			if(q2.size()>n/2){
				q1.push(q2.top());
				q2.pop();
			}
		}else{
			q1.push({f1,x});
			if(q1.size()>n/2){
				q2.push(q1.top());
				q1.pop();
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;++i){
			int f1=a[i][1];
			int f2=a[i][2];
			int f3=a[i][3];
			if(f1>=f2&&f1>=f3){//f1=max
				q1.push({f1,i});
				if(q1.size()>n/2){
					int j=q1.top().second;q1.pop();
					turn(j,1); 
				}
			}
			
			else if(f2>=f1&&f2>=f3){//f2=max
				q2.push({f2,i});
				if(q2.size()>n/2){
					int j=q2.top().second;q2.pop();
					turn(j,2); 
				}
			}
			
			else if(f3>=f1&&f3>=f2){//f3=max
				q3.push({f3,i});
				if(q3.size()>n/2){
					int j=q3.top().second;q3.pop();
					turn(j,3); 
				}
			}
		}
		int ans1=0,ans2=0,ans3=0;
		while(q1.size()){
			ans1+=q1.top().first;
			q1.pop();
		}
		while(q2.size()){
			ans2+=q2.top().first;
			q2.pop();
		}
		while(q1.size()){
			ans3+=q3.top().first;
			q3.pop();
		}
		cout<<ans1+ans2+ans3<<"\n";
	}
}
