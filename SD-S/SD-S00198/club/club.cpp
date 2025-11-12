#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


int n,m;
int ans;

struct ss{
	int x,y,z;
}a[N];

void dfs(int x,int sum,int sum1,int sum2,int sum3){
	
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	
	if(sum1<n/2){
		sum+=a[x].x;
		dfs(x+1,sum,sum1+1,sum2,sum3);
		sum-=a[x].x;
	}
	if(sum2<n/2){
		sum+=a[x].y;
		dfs(x+1,sum,sum1,sum2+1,sum3);
		sum-=a[x].y;
	}
	if(sum3<n/2){
		sum+=a[x].z;
		dfs(x+1,sum,sum1,sum2,sum3+1);
		sum-=a[x].z;
	}
}

int modb,moda;

bool cmp1(ss g,ss h){
	return g.x>h.x;
}
bool cmp2(ss g,ss h){
	return g.y>h.y;
}

void solve(){
	ans=0;
	cin>>n;
	
	moda=modb=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].y==0&&a[i].z==0){
			moda++;
		}
	}
	if(moda==n){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x;
		}
	}
	else{
		dfs(1,0,0,0,0);
	}

	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
} 
