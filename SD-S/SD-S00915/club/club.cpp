#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,t,maxz,cnt1,cnt2,cnt3;
long long ans;
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
void em(int q){
	while(!q1.empty()){
		q1.pop();
	}
	while(!q2.empty()){
		q2.pop();
	}
	while(!q3.empty()){
		q3.pop();
	}
}
void chek(int wtx){
	if(a>=b&&b>=c){
		ans+=a;
		q1.push(a-b);
		if(q1.size()>n/2){
			ans-=q1.top();
			q1.pop(); 
		}
		return ;
	}
	if(a>=c&&c>=b){
		ans+=a;
		q1.push(a-c);
		if(q1.size()>n/2){
			ans-=q1.top();
			q1.pop(); 
		}
		return ;
	}
	if(b>=a&&a>=c){
		ans+=b;
		q2.push(b-a);
		if(q2.size()>n/2){
			ans-=q2.top();
			q2.pop(); 
		}
		return ;
	}
	if(b>=c&&c>=a){
		ans+=b;
		q2.push(b-c);
		if(q2.size()>n/2){
			ans-=q2.top();
			q2.pop();
		}
		return ;
	}
	if(c>=a&&a>=b){
		ans+=c;
		q3.push(c-a);
		if(q3.size()>n/2){
			ans-=q3.top();
			q3.pop();
		}
		return ;
	}
	if(c>=b&&b>=a){
		ans+=c;
		q3.push(c-b);
		if(q3.size()>n/2){
			ans-=q3.top();
			q3.pop();
		}
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		em(1);
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			chek(1);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
