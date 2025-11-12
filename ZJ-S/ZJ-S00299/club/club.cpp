#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,ans=0;cin>>n;
	priority_queue<int>qa,qb,qc;
	for(int i=1,a,b,c;i<=n;i++){
		cin>>a>>b>>c;
		if(a>=b&&a>=c)
			qa.push(max(b-a,c-a)),ans+=a;
		else if(b>=c)
			qb.push(max(a-b,c-b)),ans+=b;
		else 
			qc.push(max(a-c,b-c)),ans+=c;
	}
	while(qa.size()>n/2)ans+=qa.top(),qa.pop();
	while(qb.size()>n/2)ans+=qb.top(),qb.pop();
	while(qc.size()>n/2)ans+=qc.top(),qc.pop();
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--)solve();
	return 0;
}
