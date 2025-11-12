#include<bits/stdc++.h>
using namespace std;

const int N=5005,mod=998244353;
int n,a[N];
int ans=0;

bool use[N]={0};
void dfs(int step,int sum,int maxx){
	if(step>n) return;
	if(sum>2*maxx && step>=3){
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			dfs(step+1,sum+a[i],max(maxx,a[i]));
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,-1);
	cout<<ans%mod;
	
	cout<<endl;
	

	return 0;
}

