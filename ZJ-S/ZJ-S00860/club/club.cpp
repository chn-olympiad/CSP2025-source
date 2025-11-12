#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
struct node{
	int val[4];
	int getmxp(){
		int res=1;
		if(val[2]>val[res]) res=2;
		if(val[3]>val[res]) res=3;
		return res;
	}
}a[maxn];
int cnt[4];
int tar;
vector<int> sufsum;
void dfs(int& res,int pos,int val){
	if(pos>tar*2){
		res=max(res,val);
		return;	
	}
	if(val+sufsum[pos]<=res) return;
	for(int i=1;i<=3;++i){
		if(cnt[i]<tar){
			++cnt[i];
			dfs(res,pos+1,val+a[pos].val[i]);
			--cnt[i];
		}
	}
}
int solve(){
	int n;
	cin>>n;
	tar=n>>1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			cin>>a[i].val[j];
		}
	}
	bool two_z=1;
	bool three_z=1;
	for(int i=1;i<=n;++i){
		two_z&=(a[i].val[2]==0);
		three_z&=(a[i].val[3]==0);
	}
	sort(a+1,a+n+1,[](node x,node y){
		return x.val[x.getmxp()]>y.val[y.getmxp()];
	});
	cnt[1]=cnt[2]=cnt[3]=0;
	long long res=0;
	if(two_z&&three_z){
		for(int i=1;i<=tar;++i) res+=a[i].val[1];
	}else if(three_z){
		priority_queue<int> pq;
		for(int i=1;i<=n;++i){
			res+=a[i].val[1];
			pq.emplace(a[i].val[2]-a[i].val[1]);
		}
		for(int i=n/2;i>=1;--i){
			res+=pq.top();
			pq.pop();
		}
	}else if(n<=30){
		sufsum.resize(n+2);
		sufsum[n+1]=0;
		for(int i=n;i>=1;--i) sufsum[i]=sufsum[i+1]+a[i].val[a[i].getmxp()];
		dfs(res,1,0);
	}else{
		vector<int> bel(n+1);
		for(int i=1;i<=n;++i){
			int pos=a[i].getmxp();
			res+=a[i].val[pos];
			++cnt[pos];
			bel[i]=pos;
		}
		if(max(cnt[1],max(cnt[2],cnt[3]))<=tar){
			return res;
		}
		int col[4]={0,1,2,3};
		if(cnt[2]>tar) swap(col[1],col[2]);
		if(cnt[3]>tar) swap(col[1],col[3]);
		//col[1] the biggest
		priority_queue<pair<int,int> > pq;
		for(int i=1;i<=n;++i){
			if(bel[i]==col[1]){
				pq.emplace(a[i].val[col[2]]-a[i].val[col[1]],i);
			}
		}
		vector<int> ppp;
		while(pq.size()>tar){
			res+=pq.top().first;
			int i=pq.top().second;
			ppp.emplace_back(i);
			pq.pop();
		}
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;++i){
			if(bel[i]==col[2]){
				pq.emplace(a[i].val[col[3]]-a[i].val[col[2]],i);
			}
		}
		for(int i:ppp) pq.emplace(a[i].val[col[3]]-a[i].val[col[2]],i);
		while(pq.size()>tar){
			res+=pq.top().first;
			pq.pop();
		}
	}
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) cout<<solve()<<'\n';
}
