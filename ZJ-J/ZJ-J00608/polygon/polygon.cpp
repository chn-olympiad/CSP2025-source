#include<bits/stdc++.h>
using namespace std;
long long a[5005],f[5005],m,n,v,ans=0;
void dfs(long long x,long long s,long long g){
	long long i;
	if (s>v&&g>=3){
		ans++;
		ans%=998244353;
	}
	for (i=x;i<m;i++){
		if (f[i]==0){
			f[i]=1;
			dfs(i,s+a[i],g+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i,j;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for (i=3;i<=n;i++){
		v=a[i];
		m=i;
		for (j=1;j<=m;j++)
			f[j]=0;
		f[i]=1;
		dfs(1,0,1);
	}
	cout<<ans;
	return 0;
}
