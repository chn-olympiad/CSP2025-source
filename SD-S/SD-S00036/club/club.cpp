#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const long long N=200;
long long maxn;
long long n;
long long ans=0;
bool cmp(vector<long long>t1,vector<long long>t2){
	return t1[0]>t2[0];
}
void dfs(vector<vector<long long>>t,long long s,long long cl1,long long cl2,long long cl3,long long sum){
	if(s>=n){
		ans=max(ans,sum);
		return;
	}
	if(cl1<maxn){
		dfs(t,s+1,cl1+1,cl2,cl3,sum+t[s][0]);
	}
	if(cl2<maxn){
		dfs(t,s+1,cl1,cl2+1,cl3,sum+t[s][1]);
	}
	if(cl3<maxn){
		dfs(t,s+1,cl1,cl2,cl3+1,sum+t[s][2]);
	}
}
void solve(){
	cin>>n;
	ans=0;
	maxn=n/2;
	vector<vector<long long>>t;
	long long flag23=1;
	for(long long i=1;i<=n;i++){
		long long a,b,c;cin>>a>>b>>c;
		if(b!=0||c!=0)flag23=0;
		t.push_back({a,b,c});
	}
	long long cnt=0;
	if(flag23){
		sort(t.begin(),t.end(),cmp);
		for(auto l:t){
			ans+=l[0];
			cnt++;
			if(cnt==maxn)break;
		}
	}else{
		dfs(t,0,0,0,0,0);
	}
	cout<<ans<<"\n";
}
int main(){
	IOS;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;cin>>t;
	while(t--)solve();
	return 0;
}

