#include<bits/stdc++.h>
using namespace std;
const int N=1e5+114;
int t,n;
int k;
int a[N][5];
int b[N];
int dfs(int x,int a1,int a2,int a3,int sum){
	if(x>n)return sum;
	int re=0;
	if(a1+1<=k)re=max(re,dfs(x+1,a1+1,a2,a3,sum+a[x][1]));
	if(a2+1<=k)re=max(re,dfs(x+1,a1,a2+1,a3,sum+a[x][2]));
	if(a3+1<=k)re=max(re,dfs(x+1,a1,a2,a3+1,sum+a[x][3]));
	
	return re;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2;
		int fa=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j>=2&&a[i][j]!=0)fa=1;
			}
		}
		if(fa==0){
			int ans=0,l=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int j=n;j>=n/2;j--)ans+=b[i][j];
			cout<<ans<<'\n';
			continue;
		}
		cout<<dfs(1,0,0,0,0)<<'\n';
	}
	return 0;
}

