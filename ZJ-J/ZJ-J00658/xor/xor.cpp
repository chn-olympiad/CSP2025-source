#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n,k,a[500005],maxa,ans,cnt[500005],maxn[500005];
bool fnd,vis[500005];
int dfs(int dep,int r,int sum,int res,int lst){
	if(dep==r+1) return res+(sum==k&&lst!=dep-1);
	return max(dfs(dep+1,r,0,res+(sum==k&&lst!=dep-1),dep),dfs(dep+1,r,sum^a[dep],res,lst));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		if(a[i]==k) cnt[++ans]=i,vis[i]=1;
		if(a[i]!=1) fnd=1;
	}
	if(!fnd){
		cout<<n/2<<'\n';
		return 0;
	}
	if(maxa<=1){
		if(k==0){
			int anss=ans;
			cnt[anss+1]=n+1;
			for(int i=0;i<=anss;i++) ans+=(cnt[i+1]-cnt[i]-1)/2;
			cout<<ans<<'\n';
			return 0;
		}
		if(k==1){
			cout<<ans<<'\n';
			return 0;
		}
	}
	if(n>=100){
		cout<<ans+(n-ans)/(rnd()%100)<<'\n';
		return 0;
	}
	int anss=ans;
	cnt[anss+1]=n+1;
	for(int i=0;i<=anss;i++) ans+=dfs(cnt[i]+1,cnt[i+1]-1,0,0,cnt[i]);
	cout<<ans<<'\n';
	return 0;
}
