#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,al;
int a[N],b[N];
void dfs(int mb,int d,int all,int ii,bool _){
	if(_){
		all+=a[ii];
		if(d>2 && all>mb)
			al++;
	}
	if(ii>1 && all+b[ii-1]>mb){
		dfs(mb,d+1,all,ii-1,true);
		dfs(mb,d+1,all,ii-1,false);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>2;i--){
		if(b[i-1]<=a[i])
			continue;
		dfs(a[i],2,0,i-1,true);
		dfs(a[i],2,0,i-1,false);
	}
	cout<<al%mod;
	return 0;
}
