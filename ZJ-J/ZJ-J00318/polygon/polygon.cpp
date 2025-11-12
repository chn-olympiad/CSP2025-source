#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool v[5005],f;
const long long mi=998244353;
void dfs(long long k){
	long long s=0,m=0,c=0;
	if(k==n+1){
		for(int i=1;i<=n;i++)s+=v[i]*a[i],m=max(m,v[i]*a[i]),c+=v[i];
	    if(s<=2*a[m]||c<3)return;
	    ans++;
	}
	dfs(k+1);
	v[k]=1;
	dfs(k+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		long long x=2;
		for(int i=3;i<=n;i++){
			x*=i;
			x%=mi;
			ans+=x;
			ans%=mi;
		}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
