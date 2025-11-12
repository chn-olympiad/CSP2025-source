#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=100010;
int t;
int n;
int a[N][3],ans;
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
void init() {
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
	memset(a,0,sizeof a);
	ans=0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>t;
	while(t--) {
		init();
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) q1.push(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) q2.push(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]) q3.push(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
		}
		if(q1.size()>n/2) {
			while(q1.size()>n/2) {
				ans-=q1.top();
				q1.pop();
			}
		} else if(q2.size()>n/2) {
			while(q2.size()>n/2) {
				ans-=q2.top();
				q2.pop();
			}
		} else if(q3.size()>n/2) {
			while(q3.size()>n/2) {
				ans-=q3.top();
				q3.pop();
			}
		}
		cout<<ans<<"\n";
	}
	return Suika;
} 