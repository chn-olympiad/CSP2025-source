#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[10010];
bool flag[10010];
int ans=0;
void dfs(int start,int shu,int yuan,int he,int maxx){
	if(shu==yuan+1){
		if(maxx*2<he){
			ans++;
		}
		return;
	}
	for(int i=start;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			int s=max(maxx,a[i]);
			dfs(i,shu+1,yuan,he+a[i],s);
			flag[i]=0;
		}
	}
}
int ji=0;
signed main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ji=1;
		}
	}
	if(ji==0){
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
		}
		cout<<ans;
	}else{
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++){
			dfs(1,1,i,0,0);
		}
		cout<<ans%998244353;		
	}

	return 0;
}
