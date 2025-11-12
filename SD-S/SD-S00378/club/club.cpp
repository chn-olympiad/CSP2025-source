#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;

int T,a[5][N],n;
ll ans;

void dfs(int p,int x,int y,int z,ll sum){
	if(p>n){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2){
		dfs(p+1,x+1,y,z,sum+a[1][p]);
	}
	if(y<n/2){
		dfs(p+1,x,y+1,z,sum+a[2][p]);
	}
	if(z<n/2){
		dfs(p+1,x,y,z+1,sum+a[3][p]);
	}
}

void A(){
	sort(a[1]+1,a[1]+n+1);
	for(int i=n;i>=n/2;i--)ans+=1LL*a[1][i];
	printf("%lld\n",ans);
}

void threeN(){
	dfs(1,0,0,0,0LL);
	printf("%lld\n",ans);
}

void solve(){
	pair<int,pair<int,int> > abc[N];
	for(int i=1;i<=n;i++){
		abc[i].first=a[1][i];
		abc[i].second.first=a[2][i];
		abc[i].second.second=a[3][i];
	}
	ll res=0;
	sort(abc+1,abc+n+1);
	for(int i=1;i<=n;i++){
		if(i<=n/2)res+=max(abc[i].second.first,abc[i].second.second);
		else res+=abc[i].first;
	}
	ans=max(ans,res);
//-------------------------------------------------------------------------	
	for(int i=1;i<=n;i++){
		abc[i].first=a[2][i];
		abc[i].second.first=a[1][i];
		abc[i].second.second=a[3][i];
	}
	res=0;
	sort(abc+1,abc+n+1);
	for(int i=1;i<=n;i++){
		if(i<=n/2)res+=max(abc[i].second.first,abc[i].second.second);
		else res+=abc[i].first;
	}
	ans=max(ans,res);
//-------------------------------------------------------------------------		
	for(int i=1;i<=n;i++){
		abc[i].first=a[3][i];
		abc[i].second.first=a[2][i];
		abc[i].second.second=a[1][i];
	}
	res=0;
	sort(abc+1,abc+n+1);
	for(int i=1;i<=n;i++){
		if(i<=n/2)res+=max(abc[i].second.first,abc[i].second.second);
		else res+=abc[i].first;
	}
	ans=max(ans,res);	
	
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	int x=0;
	for(;T--;){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[2][i])x=1;
		}
		if(n<=15){
			threeN();
		}
		else{
			if(x==0)A();
			else solve();
		}

	}
} 
