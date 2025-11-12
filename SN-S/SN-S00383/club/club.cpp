#include<bits/stdc++.h>
using namespace std;

int t,n,s[4],m;
long long ans;
struct app{
	int ai[4];
}a[100005];
void dfs(long long maxn,int ii){
	if(ii==n+1){
		ans=max(ans,maxn);
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]<m){
			s[i]++;
			dfs(maxn+a[ii].ai[i],ii+1);
			s[i]--;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].ai[1]>>a[i].ai[2]>>a[i].ai[3];
		}
		dfs(0,1);
		cout<<ans<<'\n';
		for(int i=1;i<=3;i++){
			s[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i].ai[1]=a[i].ai[2]=a[i].ai[3]=0;
		}
		ans=0;
	}
	return 0;
}
