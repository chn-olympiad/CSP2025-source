#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
int T;
int n;
int a[1000010][4]; 
int c[1000010][4][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		priority_queue<P>q[4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
//			cout<<"---------------------\n";
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					c[i][j][k]=a[i][k]-a[i][j];
//					cout<<c[i][j][k]<<" ";
				}
//				cout<<"\n";
			}
//			cout<<"---------------------\n";
			int maxx=max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxx==a[i][1]){
				ans+=a[i][1];
				q[1].push({max(c[i][1][2],c[i][1][3]),i});
				if(q[1].size()>n/2){
					int id=q[1].top().second;q[1].pop();
					if(c[id][1][2]>c[id][1][3]){
						ans+=c[id][1][2];
						q[2].push({max(c[id][2][3],c[id][2][1]),id});
					} 
					else{
						ans+=c[id][1][3];
						q[3].push({max(c[id][3][1],c[id][3][2]),id});
					}
				}
			}
			else if(maxx==a[i][2]){
				ans+=a[i][2];
				q[2].push({max(c[i][2][3],c[i][2][1]),i});
				if(q[2].size()>n/2){
					int id=q[2].top().second;q[2].pop();
					if(c[id][2][1]>c[id][2][3]){
						ans+=c[id][2][1];
						q[1].push({max(c[id][1][2],c[id][1][3]),id});
					} 
					else{
						ans+=c[id][2][3];
						q[3].push({max(c[id][3][1],c[id][3][2]),id});
					}
				}
			}
			else if(maxx==a[i][3]){
				ans+=a[i][3];
				q[3].push({max(c[i][3][1],c[i][3][2]),i});
				if(q[3].size()>n/2){
					int id=q[3].top().second;q[3].pop();
					if(c[id][3][1]>c[id][3][2]){
						ans+=c[id][3][1];
						q[1].push({max(c[id][1][2],c[id][1][3]),id});
					} 
					else{
						ans+=c[id][3][2];
						q[2].push({max(c[id][2][1],c[id][2][3]),id});
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//调了半个小时发现没写pop（doge） 
