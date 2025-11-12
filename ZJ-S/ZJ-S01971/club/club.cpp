#include<bits/stdc++.h>
using namespace std;
int n,ans,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>t;
	while(t--){
		priority_queue<int>a,b,c;
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			int mx=max(aa,max(bb,cc));
			ans+=mx;
			if(mx==aa)a.push(-min(aa-bb,aa-cc));
			if(mx==bb)b.push(-min(bb-aa,bb-cc));
			if(mx==cc)c.push(-min(cc-bb,cc-aa));
		}
		while(a.size()>n/2){
			ans+=a.top();
			a.pop();
		}
		while(b.size()>n/2){
			ans+=b.top();
			b.pop();
		}
		while(c.size()>n/2){
			ans+=c.top();
			c.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}