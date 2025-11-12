#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],ans;
long long mod=998244353;
void dfs(long long n,long long x,long long sum){
//	cout<<n<<' '<<x<<' '<<sum<<'\n';
	if(sum==x+1){
		long long mx=0,sun=0;
		for(long long i=1;i<=sum;i++){
			sun+=a[b[i]];
			mx=max(mx,a[b[i]]);
//			cout<<a[b[i]]<<' ';
		}
		if(sun>mx*2){
			ans++;
			ans%=mod;
		}
//		cout<<'\n'<<sun<<' '<<mx<<'\n';
//		cout<<'\n';
		return ;
	}
	for(long long i=b[sum]+1;i<=n;i++){
//		if((n-i+1)<x)break;
		b[sum+1]=i;
		dfs(n,x,sum+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,mmx=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mmx=max(mmx,a[i]);
	}
//	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(mmx==1){
		long long suum=1,xxx=n*(n-1)/2;
		for(long long i=1;i<=n;i++){
			suum*=2;
		}
		suum=suum-1-n-xxx;
		suum%=mod;
		cout<<suum;
		return 0;
	}
	for(long long i=2;i<n;i++){
		dfs(n,i,0);
	}
	cout<<ans;
	return 0;
}
/*
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
1 2 3 4
1 2 3 5
1 2 4 5
1 3 4 5
2 3 4 5
1 2 3 4 5


*/
