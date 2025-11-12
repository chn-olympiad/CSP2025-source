#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
struct node{
	long long x,y,z;
	bool operator >(const node& b)const{
		return x-max(y,z)>b.x-max(b.y,b.z);
	}
}a[100005];
struct bb{
	long long x,y,z;
	bool operator >(const bb& b)const{
		return y-max(x,z)>b.y-max(b.x,b.z);
	}
};
struct cc{
	long long x,y,z;
	bool operator >(const cc& b)const{
		return z-max(x,y)>b.z-max(b.x,b.y);
	}
};
priority_queue<node,vector<node>,greater<node> >qa;
priority_queue<bb,vector<bb>,greater<bb> >qb;
priority_queue<cc,vector<cc>,greater<cc> >qc;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		while(!qa.empty())qa.pop();
		while(!qb.empty())qb.pop();
		while(!qc.empty())qc.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(qa.size()<n/2){
					qa.push({a[i].x,a[i].y,a[i].z});ans+=a[i].x;
				}
				else{
					if(a[i].y==a[i].x){
						qb.push({a[i].x,a[i].y,a[i].z})	;ans+=a[i].x;
					}
					else if(a[i].x==a[i].z){
						qc.push({a[i].x,a[i].z,a[i].y})	;ans+=a[i].x;
					}
					else{
						auto q=qa.top() ;
						if(a[i].x-q.x+max(q.y,q.z)>=max(a[i].y,a[i].z)){
							qa.pop();
							qa.push({a[i].x,a[i].y,a[i].z});	
							if(q.y>q.z){
								qb.push({q.x,q.y,q.z});
							}
							else qc.push({q.x,q.y,q.z});
							ans+=a[i].x-q.x+max(q.y,q.z);
						}
						else{
							if(a[i].y>a[i].z){
								qb.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].y;
							}
							else {
								qc.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].z;
							}
						}
					}
				}
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(qb.size()<n/2){
					qb.push({a[i].x,a[i].y,a[i].z});ans+=a[i].y;
				}
				else{
					if(a[i].y==a[i].x){
						qb.push({a[i].x,a[i].y,a[i].z})	;ans+=a[i].y;
					}
					else if(a[i].y==a[i].z){
						qc.push({a[i].x,a[i].y,a[i].z})	;ans+=a[i].y;
					}
					else{
						auto q=qb.top() ;
					//	cout<<q.x<<" "<<q.y<<" "<<q.z<<"\n";
						if(a[i].y-q.y+max(q.x,q.z)>=max(a[i].x,a[i].z)){
						//	cout<<1;
					//	cout<<q.x<<" "<<q.y<<" "<<q.z<<"\n";
							qb.pop();
							qb.push({a[i].x,a[i].y,a[i].z});	
						//	cout<<q.x<<" "<<q.y<<" "<<q.z<<"\n";
							if(q.x>q.z){
								qa.push({q.x,q.y,q.z});
							}
							else qc.push({q.x,q.y,q.z});
					//		cout<<a[i].y<<" "<<q.y<<" "<<max(q.x,q.z)<<" ";
							ans+=a[i].y-q.y+max(q.x,q.z);
						//	cout<<ans<<"\n";
						}
						else{
							if(a[i].x>a[i].z){
								qa.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].x;
							}
							else {
								qc.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].z;
							}
						}
					}
				}
			}
			else {
				if(qc.size()<n/2){
					qc.push({a[i].x,a[i].y,a[i].z});ans+=a[i].z;
				}
				else{
					if(a[i].z==a[i].x){
						qa.push({a[i].x,a[i].y,a[i].z})	;ans+=a[i].z;
					}
					else if(a[i].y==a[i].z){
						qb.push({a[i].x,a[i].y,a[i].z})	;ans+=a[i].z;
					}
					else{
						auto q=qc.top() ;
						if(a[i].z-q.z+max(q.y,q.x)>=max(a[i].y,a[i].x)){
							qc.pop();
							qc.push({a[i].x,a[i].y,a[i].z});	
							if(q.x>q.y){
								qa.push({q.x,q.y,q.z});
							}
							else qb.push({q.x,q.y,q.z});
							ans+=a[i].z-q.z+max(q.y,q.x);
						}
						else{
							if(a[i].x>a[i].y){
								qa.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].x;
							}
							else {
								qb.push({a[i].x,a[i].y,a[i].z});
								ans+=a[i].y;
							}
						}
					}
				}
			}
			//cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}