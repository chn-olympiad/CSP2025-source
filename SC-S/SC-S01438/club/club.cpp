#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		int cnt[3];cnt[0]=cnt[1]=cnt[2]=0;
		priority_queue<int,vector<int>,greater<int> > q;
		int ans=0;
		for(int i = 0;i<=2;i++){
			while(!q.empty())q.pop();
			for(int j = 1;j<=n;j++){
				if(a[j][i]==max({a[j][0],a[j][1],a[j][2]})){
					ans+=a[j][i];
					q.push(2*a[j][i]-a[j][0]-a[j][1]-a[j][2]+
						   min({a[j][0],a[j][1],a[j][2]})); 
					a[j][i]++;
				} 
			}
			while(q.size()>n/2)ans-=q.top(),q.pop();
		}
		cout<<ans<<"\n";
	}
} 