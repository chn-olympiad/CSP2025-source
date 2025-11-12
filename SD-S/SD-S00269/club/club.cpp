//ALL FOR MYSELF, NOT ANYONE ELSE


//做法假的，根本不会 
#include<bits/stdc++.h>
//#define TERRY_MC
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n,cnt[4],ans,dp[80][3][80][80][80];
struct node {
	int num[4],id;
	pair<int,int> getmax(){
		int res=0,resid=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]<=n/2)
				if(res<num[i])
					res=num[i],resid=i; 
		return {resid,res};
	}
	friend bool operator<(node a,node b) {
		return a.getmax().second>b.getmax().second;
	}
	friend bool operator>(node a,node b) {
		return a.getmax().second<b.getmax().second;
	}
};
multiset<node> s;
vector<node> awa;
int dfs(int i,int _123, int _1, int _2, int _3) {
	if(dp[i][_123-1][_1][_2][_3]!=-1)
		return dp[i][_123-1][_1][_2][_3];
	if(i==n-1) return awa[i].num[_123];
	int res=0;
	if(_1<n/2)
		res=max(res,dfs(i+1,1,_1+1,_2,_3));
	if(_2<n/2)
		res=max(res,dfs(i+1,2,_1,_2+1,_3));
	if(_3<n/2)
		res=max(res,dfs(i+1,3,_1,_2,_3+1));
	return dp[i][_123-1][_1][_2][_3]=res+awa[i].num[_123];
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef TERRY_MC
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	cin>>t;
	while(t--) {
		s.clear();
		cin>>n;
		if(n<80) {//拼盘 
			for(int i=0;i<=n;i++)
				for(int j=0;j<3;j++)
					for(int k=0;k<=n;k++)
						for(int l=0;l<=n;l++)
							for(int m=0;m<=n;m++)
								dp[i][j][k][l][m]=-1;
			awa.clear();
			for(int i=1;i<=n;i++) {
				node o;
				cin>>o.num[1]>>o.num[2]>>o.num[3]; 
				o.id=i;
				awa.push_back(o);
			}
			cout<<max(dfs(0,1,1,0,0),max(dfs(0,2,0,1,0),dfs(0,3,0,0,1)))<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) {
			node o;
			cin>>o.num[1]>>o.num[2]>>o.num[3]; 
			o.id=i;
			s.insert(o);
		}
		
//		cerr<<s.size()<<endl; 
		ans=0;
		while(!s.empty()) {
			node o = *s.begin();
//			cerr<<o.id<<endl;
			s.erase(s.begin());
			cnt[o.getmax().first]++;
			ans+=cnt[o.getmax().second];
		}
		cout<<ans<<endl;
//		cerr<<endl;
	}
	return 0;
}

