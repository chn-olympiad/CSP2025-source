#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N],b[N],c[N];
int ans;
//int dp[210][210][3][210];
void dfs(int now,int na,int nb,int nc,int sum){
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(na<n/2){
		dfs(now+1,na+1,nb,nc,sum+a[now]);
	}
	if(nb<n/2){
		dfs(now+1,na,nb+1,nc,sum+b[now]);
	}
	if(nc<n/2){
		dfs(now+1,na,nb,nc+1,sum+c[now]);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool tc=0,tb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) tb=1;
			if(c[i]!=0) tc=1;
		}
		if(tb==0&&tc==0){
			int ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
