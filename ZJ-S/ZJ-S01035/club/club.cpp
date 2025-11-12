#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
long long ans=0;
priority_queue<int,vector<int>,greater<int> >qu[3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		for(int i=0;i<3;i++){
			while(!qu[i].empty())qu[i].pop();
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				qu[0].push(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
			}
			else if(a[i][1]>=a[i][2]){
				qu[1].push(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
			}
			else{
				qu[2].push(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
			}
			ans=ans+max(a[i][0],max(a[i][1],a[i][2]));
		}
		for(int i=0;i<3;i++){
			while(qu[i].size()>n/2){
				ans=ans-qu[i].top();
				qu[i].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}