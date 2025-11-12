#include<bits/stdc++.h>
using namespace std;

const int N=200005,inf=2e9;
priority_queue<int> q[4];
int n;
int a[N][4];
int ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=3;i++)
			while(q[i].size())
				q[i].pop();

		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=-inf,mn;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx){
					mx=a[i][j];
					mn=j;
				}
			}
			ans+=mx;
			int delt=-inf;
			for(int j=1;j<=3;j++){
				if(j==mn)
					continue;
				delt=max(delt,a[i][j]-mx);//减少的尽可能小  大根堆啊 
			}
			q[mn].push(delt); 
		}
//		cout<<ans<<'\n';
		for(int i=1;i<=3;i++){
			while(q[i].size()>n/2){
				int u=q[i].top();
				q[i].pop();
				ans=ans+u; 
//				cout<<u<<'\n'; 
			}
		}
		cout<<ans<<'\n';
	}
	


	return 0;
}


