#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> aa,bb,cc;
long long t,n,a,b,c,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		while(!aa.empty()){
			aa.pop();
		}
		while(!bb.empty()){
			bb.pop();
		}
		while(!cc.empty()){
			cc.pop();
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			if(a>=b&&b>=c){
				aa.push(b-a);
				ans+=a;
			}
			else if(a>=c&&c>=b){
				aa.push(c-a);
				ans+=a;
			}
			else if(b>=a&&a>=c){
				bb.push(a-b);
				ans+=b;
			}
			else if(b>=c&&c>=a){
				bb.push(c-b);
				ans+=b;
			}
			else if(c>=a&&a>=b){
				cc.push(a-c);
				ans+=c;
			}
			else if(c>=b&&b>=a){
				cc.push(b-c);
				ans+=c;
			}
		}
		while(aa.size()>(n/2)){
			ans+=aa.top();
			//cout<<aa.top()<<' ';
			aa.pop();
		}
		while(bb.size()>(n/2)){
			ans+=bb.top();
			//cout<<bb.top()<<' ';
			bb.pop();
		}
		while(cc.size()>(n/2)){
			ans+=cc.top();
			cc.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
