#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
bool vis[500005];
long long cnt;
int n;
map<string,int>mp;
map<int,long long>ca;
void dfs(int x){
	if(x>3){
		long long ans=0;
		string s;
		for(int i=1;i<x;i++){
			c[i]=b[i];
		}
		sort(c+1,c+x);
		for(int i=1;i<x;i++){
			ans+=c[i];
			s+=to_string(c[i]);
		} 
		mp[s]++;
		if(ans>c[x-1]*2&&mp[s]==1){
			cnt=(cnt+1)%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			b[x]=a[i];
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ca[a[i]]++;
	}
	sort(a+1,a+n+1);
	dfs(1);
	for(auto i:ca){
		cnt+=i.second-1;
	}
	cout<<cnt;
	return 0;
}
