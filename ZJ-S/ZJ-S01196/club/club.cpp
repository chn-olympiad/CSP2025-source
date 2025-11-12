#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
long long n,t,ans,a[N][5];
bool flag;
void dfs(int id,int x,int y,int z,long long sum){
	if(id>n){
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2) dfs(id+1,x+1,y,z,sum+a[id][1]);
	if(y+1<=n/2) dfs(id+1,x,y+1,z,sum+a[id][2]);
	if(z+1<=n/2) dfs(id+1,x,y,z+1,sum+a[id][3]);
}
vector<long long> v;
bool cmp(long long x,long long y){
	return x>y;
}
void solve(){
	cin>>n;
	flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0 && a[i][3]!=0) flag=false;
	}
	ans=0;
	if(flag){
		v.clear();
		for(int i=1;i<=n;i++){
			v.push_back(a[i][1]);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<n/2;i++){
			ans+=v[i];
		}
	}else{
		dfs(1,0,0,0,0);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
