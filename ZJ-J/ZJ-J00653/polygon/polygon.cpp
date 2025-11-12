#include<bits/stdc++.h>
using namespace std;
int n;
const long long mod=998244353;
int a[5025];
long long ans,sum;
unordered_map<int,long long> mp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	mp[0]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		queue<pair<int,long long> > q;
		for(auto j:mp){
			if(j.first>a[i]) ans=(ans+j.second)%mod;
			q.push(j);
		}while(!q.empty()){
			auto p=q.front();
			q.pop();
			mp[p.first+a[i]]=(mp[p.first+a[i]]+p.second)%mod;
		}
	}cout<<ans;
	return 0;
}
