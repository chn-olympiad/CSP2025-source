#include <iostream>
#include <queue>
using namespace std;
const int N=2e5+5;
struct node{
	int n,x;
	friend operator<(node x,node y){
		return x.x>y.x;
	}
};
int a[N][4];
priority_queue<node> d1,d2,d3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int half=n/2;
		int ans=0;
		while(!d1.empty()) d1.pop();
		while(!d2.empty()) d2.pop();
		while(!d3.empty()) d3.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int a1=a[i][1],a2=a[i][2],a3=a[i][3];
			if(a1>=a2 && a1>=a3){
				if((int)d1.size()==half){
					node tmp=d1.top();
//					if(a[tmp.n][2]>=a[tmp.n][3]){
					if(abs(tmp.x+a2-a[tmp.n][2]-a1)>=abs(tmp.x+a3-a[tmp.n][3]-a1)){
						if(tmp.x+a2>=a[tmp.n][2]+a1){
							d2.push({i,a2});
							ans+=a2;
						}else{
							d1.pop();
							d1.push({i,a1});
							d2.push({tmp.n,a[tmp.n][2]});
							ans=ans-tmp.x+a1+a[tmp.n][2];
						}
					}else{
						if(tmp.x+a3>=a[tmp.n][3]+a1){
							d3.push({i,a3});
							ans+=a3;
						}else{
							d1.pop();
							d1.push({i,a1});
							d3.push({tmp.n,a[tmp.n][3]});
							ans=ans-tmp.x+a1+a[tmp.n][3];
						}
					}
				}else{
					d1.push({i,a1});
					ans+=a1;
				}
			}else if(a1<a2 && a2>=a3){
				if((int)d2.size()==half){
					node tmp=d2.top();
//					if(a[tmp.n][1]>=a[tmp.n][3]){
					if(abs(tmp.x+a1-a[tmp.n][1]-a2)>=abs(tmp.x+a3-a[tmp.n][3]-a2)){
						if(tmp.x+a1>=a[tmp.n][1]+a2){
							d1.push({i,a1});
							ans+=a1;
						}else{
							d2.pop();
							d2.push({i,a2});
							d1.push({tmp.n,a[tmp.n][1]});
							ans=ans-tmp.x+a2+a[tmp.n][1];
						}
					}else{
						if(tmp.x+a3>=a[tmp.n][3]+a2){
							d3.push({i,a3});
							ans+=a3;
						}else{
							d2.pop();
							d2.push({i,a2});
							d3.push({tmp.n,a[tmp.n][3]});
							ans=ans-tmp.x+a2+a[tmp.n][3];
						}
					}
				}else{
					d2.push({i,a2});
					ans+=a2;
				}
			}else if(a1<a3 && a2<a3){
				if((int)d3.size()==half){
					node tmp=d3.top();
//					if(a[tmp.n][1]>=a[tmp.n][2]){
					if(abs(tmp.x+a1-a[tmp.n][1]-a3)>=abs(tmp.x+a2-a[tmp.n][2]-a3)){
						if(tmp.x+a1>=a[tmp.n][1]+a3){
							d1.push({i,a1});
							ans+=a1;
						}else{
							d3.pop();
							d3.push({i,a3});
							d1.push({tmp.n,a[tmp.n][1]});
							ans=ans-tmp.x+a3+a[tmp.n][1];
						}
					}else{
						if(tmp.x+a2>=a[tmp.n][2]+a3){
							d2.push({i,a2});
							ans+=a2;
						}else{
							d3.pop();
							d3.push({i,a3});
							d2.push({tmp.n,a[tmp.n][2]});
							ans=ans-tmp.x+a3+a[tmp.n][2];
						}
					}
				}else{
					d3.push({i,a3});
					ans+=a3;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
