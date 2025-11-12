#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
ll T,n,a[N][4],f[N],ans,sum;
void dfs(ll x,ll b,ll c,ll d){
	if(b>n/2||c>n/2||d>n/2) return ;
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	sum+=a[x][1];
	dfs(x+1,b+1,c,d);
	sum-=a[x][1];
	sum+=a[x][2];
	dfs(x+1,b,c+1,d);
	sum-=a[x][2];
	sum+=a[x][3]; 
	dfs(x+1,b,c,d+1);
	sum-=a[x][3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(f,0,sizeof f);
		ans=-inf;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j],f[i]+=a[i][j];
		if(n<=30) dfs(1,0,0,0);
		else{
			sort(f+1,f+n+1);
			ans=0;
			for(int i=n;i>n/2;i--) ans+=f[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

