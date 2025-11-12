#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N][5],cnt[5],ans;
bool A=1,B=1;
void dfs(int u,int sum){
	if(u>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]*2<n){
			cnt[i]++;
			dfs(u+1,sum+a[u][i]);
			cnt[i]--;
		}
	}
	
}
int main(){
//	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(A&&a[i][2]) A=0;
			else if(B&&a[i][3]) B=0;
		}
		if(n<=10) dfs(1,0);
		else if(A){
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>=n/2;i--) ans+=a[1][i];
			
		}
		else if(B){
			for(int i=1;i<=n;i++){
//				for(int )
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
