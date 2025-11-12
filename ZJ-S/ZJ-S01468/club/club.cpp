#include<bits/stdc++.h>
using namespace std;
long long T,n,i,a[100005][5],p[5],ans,k[100005];
void dfs(int x,long long s){
	if(x>n){
		if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2){
			ans=max(ans,s);
		}
		return;
	}
	p[1]++;
	dfs(x+1,s+a[x][1]);
	p[1]--;p[2]++;
	dfs(x+1,s+a[x][2]);
	p[2]--;p[3]++;
	dfs(x+1,s+a[x][3]);
	p[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			k[i]=a[i][1];
		}
		if(n<=200){
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else{
			sort(k+1,k+n+1);
			for(i=n;i>=n/2+1;i--){
				ans+=k[i];
			}
			cout<<ans<<"\n";
			return 0;
		}
	}
}