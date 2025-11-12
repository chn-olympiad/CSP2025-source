#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
const int mod=998244353;
long long n,cnt=0;
void dfs(int s,int sum,int maxn){
	if(maxn*2<sum) cnt++;
	cnt%=mod;
	for(int i=s+1;i<=n;i++){
		dfs(i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) dfs(i,a[i],a[i]);
	cout<<cnt;
	return 0;
}
