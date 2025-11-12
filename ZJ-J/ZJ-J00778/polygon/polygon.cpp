#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,a[5010],sum,d[5010],b[5010],ans,maxx,t[50010],x,k;
const int mod=998244353;
void dfs(int k,int r){
	if(k==r+1){
		int sum=0,maxx=0;
		for(int i=1;i<k;i++){
			sum+=d[i];
			maxx=max(maxx,d[i]);
		}
		if(sum>maxx*2){
			/*for(int i=1;i<k;i++){
				cout<<d[i]<<" ";
			}
			cout<<endl;*/
			ans++;
			ans%=mod;
		}
		t[sum]++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0&&a[i]>=d[k-1]){
			b[i]=1;
			d[k]=a[i];
			dfs(k+1,r);
			b[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<ans%mod;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/