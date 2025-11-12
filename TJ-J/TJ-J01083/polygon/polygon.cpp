#include<bits/stdc++.h>
using namespace std;
const long long mod=99824353;
long long n,uv;
long long cnt;
long long a[5005],vis[5005];
long long yy[5005];
map<vector<long long>,long long> mp;
void dfs(long long x,long long maxx,long long l,long long p){
	if(p==uv){
		vector<long long> v;
		v.push_back(p);
		for(long long i=1;i<=n;i++){
			if(vis[i]==1){
				v.push_back(a[i]);
			}
		}
		for(long long i=1;i<=n;i++){
			if(vis[i]==1)
				v.push_back(i);
		}
		if(x>maxx*2){
			if(mp[v]==0){
				cnt+=1;
				mp[v]=1;
			}
		}
		return;
	}
	if(l==n+1){
		return;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(x+a[i],max(maxx,a[i]),l+1,p+1);
		vis[i]=0;

	}
	dfs(x,maxx,l+1,p);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		yy[a[i]]++;
	}
	for(long long i=3;i<=n;i++){
		uv=i;
		dfs(0,0,1,0);
		cnt%=mod;
	}
	cout<<cnt;
	return 0;
}
