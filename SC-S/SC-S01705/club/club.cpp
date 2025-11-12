#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005],b[100005],c[100005],ans;
void dfs(int d,int sum,int sa,int sb,int sc){
	if(d>n){
		ans=max(ans,sum);
		return;
	}
	if(sa>0){
		dfs(d+1,sum+a[d],sa-1,sb,sc);
	}
	if(sb>0){
		dfs(d+1,sum+b[d],sa,sb-1,sc);
	}
	if(sc>0){
		dfs(d+1,sum+c[d],sa,sb,sc-1);
	}
	return;
}
void bs(){
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	dfs(1,0,n/2,n/2,n/2);
	cout<<ans<<"\n";
	return;
}
void tpa(){
	int x=0;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		x++;
		ans+=a[i];
		if(x==n/2){
			break;
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		if(n<=15){
			bs();
			continue;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		if(c[n]==0){
			if(b[n]==0){
				tpa();
			}
		}
	}
	return 0;
}
