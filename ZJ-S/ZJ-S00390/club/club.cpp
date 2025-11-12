#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],mx[100005],md[100005],picc[100005];
struct node{
	int x;
	bool operator<(node u)const{
		return picc[x]>picc[u.x];
	}
};
priority_queue<node>q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;int ans=0;
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mx[i]=1;
			int mn=1;
			for(int j=1;j<=3;j++){
				if(a[i][j]>a[i][mx[i]])mx[i]=j;
				if(a[i][j]<a[i][mn])mn=j;
			}
			md[i]=6-mx[i]-mn;
			ans+=a[i][mx[i]];
			picc[i]=a[i][mx[i]]-a[i][md[i]];
		}
		for(int i=1;i<=n;i++){
			if(q[mx[i]].size()==n/2){
				int mm=q[mx[i]].top().x;
				if(picc[mm]<picc[i]){
					q[mx[i]].pop();
					q[md[i]].push({mm});
					q[mx[i]].push({i});
					ans-=picc[mm];
				}
				else q[md[i]].push({i}),ans-=picc[i];
			}
			else q[mx[i]].push({i});
		}
		cout<<ans<<"\n";
	}
	return 0;
}
