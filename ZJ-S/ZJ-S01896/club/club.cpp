#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0,ca=0,cb=0,cc=0;
		priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
		for(int i=1; i<=n; i++) {
			int a,b,c,lose;
			cin>>a>>b>>c;
			int mx=max(a,max(b,c));
			ans+=mx;
			if(mx==a) {
				ca++;
				lose=min(a-b,a-c);
				q1.push(lose);
			} else if(mx==b) {
				cb++;
				lose=min(b-a,b-c);
				q2.push(lose);
			} else {
				cc++;
				lose=min(c-b,c-a);
				q3.push(lose);
			}
		}
		while(ca>n/2) {
			ans-=q1.top();
			q1.pop();
			ca--;
		}
		while(cb>n/2) {
			ans-=q2.top();
			q2.pop();
			cb--;
		}
		while(cc>n/2) {
			ans-=q3.top();
			q3.pop();
			cc--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
