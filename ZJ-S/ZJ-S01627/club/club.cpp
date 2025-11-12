#include<bits/stdc++.h>
using namespace std;
long long t,book[100100],n,a[100100],b[100100],c[100100],f[100100][10];
long long left(long long x,long long y){
	return x;
}
long long dfs(long long x,long long ans){
	if(x==n+1){
//		cout<<"x:"<<x<<" ans:"<<ans<<" d:"<<ans<<"\n";
		return ans;
	}
//	long long d=max({left(left(book[1]<n/2,book[1]++)*dfs(x+1,ans+a[x]),book[1]--),left(left(book[2]<n/2,book[2]++)*dfs(x+1,ans+b[x]),book[2]--),left(left(book[3]<n/2,book[3]++)*dfs(x+1,ans+c[x]),book[3]--)});
//	cout<<"x:"<<x<<" ans:"<<ans<<" d:"<<d<<"\n";
//	return d;
	long long maxs=0;
	if(book[1]<n/2){
		book[1]++;
		maxs=dfs(x+1,ans+a[x]);
		book[1]--;
	}
	if(book[2]<n/2){
		book[2]++;
		maxs=max(maxs,dfs(x+1,ans+b[x]));
		book[2]--;
	}
	if(book[3]<n/2){
		book[3]++;
		maxs=max(maxs,dfs(x+1,ans+c[x]));
		book[3]--;
	}
	return maxs;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(book,0,sizeof(book));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		cout<<dfs(1,0)<<"\n";
	}
}
