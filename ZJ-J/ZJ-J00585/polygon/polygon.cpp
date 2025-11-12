#include<bits/stdc++.h>
using namespace std;

long long N=998244353;
long long n,a[5111],v[5111],ans;
void dfs(int d){
	if(d>=n+1){
		long long s1=0,s2=0,m=-1;
		for(int i=1;i<=n;i++){
			if(v[i]){
				s1+=a[i];
				s2++;
				m=max(m,a[i]);
			}
		}
		if(s1>m*2&&s2>2){
			ans++;
		}
		ans%=N;
		return;
	}
	v[d]=0;
	dfs(d+1);
	v[d]=1;
	dfs(d+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
