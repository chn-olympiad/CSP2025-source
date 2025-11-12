#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;

struct node{
	int c,v,s;
	bool operator < (const node & x) const{
		return s<x.s;
	}
};
int n,m,t,w[N][4];
priority_queue<node> q[4];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int ans=0,p=0;
		for(int k=1; k<=3; k++){
			while(!q[k].empty()) q[k].pop();
		}
		cin >> n;
		for(int i=1; i<=n; i++){
			int m1=0,m2=0,s1=0,s2=0;
			for(int k=1; k<=3; k++){
				cin >> w[i][k];
				if(w[i][k]>=m1){
					s2=s1;
					s1=k;
					m2=m1;
					m1=w[i][k];
				}
				else if(w[i][k]>=m2){
					s2=k;
					m2=w[i][k];
				}
			}
			if(s1!=p){
				q[s1].push({i,m1,m2-m1});
				ans+=m1;
			}
			else{
				if(q[s1].top().s+m1<=m2){
					ans+=m2;
				}
				else{
					ans+=q[s1].top().s;
					q[s1].pop();
					q[s1].push({i,m1,m2-m1});
					ans+=m1;
				}
			}
			if(q[s1].size()==n/2) p=s1;
		}
		cout << ans <<'\n';
	}
	return 0;
}
