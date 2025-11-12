#include<bits/stdc++.h>

using namespace std;
const long long N=998244353;

long long n,a[5010];
long long ans=0;

void dfs(long long dep,long long sum,long long dep_Max){
	if(sum>dep_Max*2 && dep!=0){
		ans++;
		ans%=N;
	}
	for(int i=dep+1;i<=n;i++){
		dfs(i,sum+a[i],max(dep_Max,a[i]));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

