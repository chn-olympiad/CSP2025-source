#include<bits/stdc++.h>
using namespace std;
const int N=5555,mod=998244353;
int n,a[N],b[N];
long long ans=0;
void dfs(int i,int cnt,int x,int k){
	if(cnt>x && k>2){
		ans=(ans+(1<<i)%mod)%mod;
		return ;
	}
	for (int j=i;j>0;j--){
		dfs(j-1,cnt+a[j],x,k+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=n;i>0;i--){
		dfs(i-1,0,a[i],1);
	}
	cout<<ans;
	return 0;
}
