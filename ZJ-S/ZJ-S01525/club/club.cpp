#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q1,q2,q3;

void clearall(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long ans=0;
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b && a>=c){
				ans+=a;
				q1.push(a-max(b,c));
			}
			else if(b>=a && b>=c){
				ans+=b;
				q2.push(b-max(a,c));
			}
			else{
				ans+=c;
				q3.push(c-max(a,b));
			}
		}
		int bound=n/2;
		if(q1.size()>bound){
			while(q1.size()>bound){
				ans-=q1.top();
				q1.pop();
			}
		}
		else if(q2.size()>bound){
			while(q2.size()>bound){
				ans-=q2.top();
				q2.pop();
			}
		}
		else if(q3.size()>bound){
			while(q3.size()>bound){
				ans-=q3.top();
				q3.pop();
			}
		}
		printf("%lld\n",ans);
		clearall();
	}
	return 0;
}
