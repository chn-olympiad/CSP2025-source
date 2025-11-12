#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7,M=300,inf=1e18,mod=1e9+7;
int T,n,a[3][N],c[5];
priority_queue<pair<int,int> > q[N];
bool vis[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int x;
			cin>>x;
			a[j][i]=x;
			q[j].push({x,i});
		}
	}
	int op=n/2;
	int c1=0,c2=0,c3=0,sum=0;
	while(!q[1].empty()&&!q[2].empty()&&!q[3].empty()&&c[1]+c[2]+c[3]!=n){
		for(int i=1;i<=3;i++){
			while(!q[i].empty()&&vis[q[i].top().second])q[i].pop();
			//cout<<q[i].top().second<<" ";
			if(q[i].size()==1){
				int oi=q[i].top().second;
				sum+=max(a[1][oi],max(a[2][oi],a[3][oi]));
				cout<<sum<<"\n";
				return ;
			}
			if(c[i]<op){
				c[i]++;
				vis[q[i].top().second]=true;
				sum+=q[i].top().first;
				q[i].pop();
			}
		}
		cout<<"\n";
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0 
2
10 9 8
4 0 0
*/
