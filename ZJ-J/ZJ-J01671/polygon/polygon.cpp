#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[10001];
int v[10001];
void dfs(int k,int sum,int maxx,int j){
	if(k==n+1){
		return;
	}
	if(k>=3&&sum>maxx*2){
		ans++;
	}
	for(int i=j;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			sum+=a[i];
			if(a[i]>maxx){
				k=maxx;
				maxx=a[i];
			}
			dfs(k+1,sum,maxx,i);
			maxx=k;
			v[i]=0;
			sum-=a[i];
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans%998244353;
	return 0;
} 
