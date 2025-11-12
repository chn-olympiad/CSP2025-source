#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int T,n,a[N][4],t[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int sum=0,len=n/2;
		priority_queue<int,vector<int>,greater<int>> qa,qb,qc;
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			int maxn=max({a[i][0],a[i][1],a[i][2]});
			sum+=maxn;
			if(a[i][0]==maxn) qa.push(maxn-max(a[i][1],a[i][2]));
			else if(a[i][1]==maxn) qb.push(maxn-max(a[i][0],a[i][2]));
			else qc.push(maxn-max(a[i][0],a[i][1]));
		}
		int qaz=qa.size(),qbz=qb.size(),qcz=qc.size();
		while(qaz-->len){
			sum-=qa.top();
			qa.pop();
		}
		while(qbz-->len){
			sum-=qb.top();
			qb.pop();
		}
		while(qcz-->len){
			sum-=qc.top();
			qc.pop();
		}
		cout<<sum<<'\n';
	}
	return 0;
}