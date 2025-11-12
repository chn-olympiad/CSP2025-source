#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],sz[4],big[N][2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]){
				big[i][1]=1;
				big[i][0]=2;
			}else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]){
				big[i][1]=1;
				big[i][0]=3;
			}else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){
				big[i][1]=2;
				big[i][0]=3;
			}else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
				big[i][1]=2;
				big[i][0]=1;
			}else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]){
				big[i][1]=3;
				big[i][0]=1;
			}else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]){
				big[i][1]=3;
				big[i][0]=2;
			}
		}
		priority_queue<int,vector<int>,greater<int>>q[4];
		sz[1]=sz[2]=sz[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=big[i][1];
			ans+=a[i][x];
			sz[x]++;
			q[x].push(a[i][x]-a[i][big[i][0]]);
		}
		int x=0;
		if(sz[1]>=n/2)x=1;
		else if(sz[2]>=n/2)x=2;
		else if(sz[3]>=n/2)x=3;
		if(x!=0){
			while(sz[x]>n/2){
				ans-=q[x].top();
				sz[x]--;
				q[x].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}