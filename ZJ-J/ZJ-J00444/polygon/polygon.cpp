#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
int n;
int ans,mo=998244353;
void dfs(int d,int x,int y){
	if(d>n){
		if(x>2*y) ans=(ans+1)%mo;
		return;
	}
	dfs(d+1,x,y);
	dfs(d+1,x+a[d],max(y,a[d]));
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a.resize(n+1,0);
	bool v=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) v=0;
	}
	sort(a.begin()+1,a.begin()+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<(a[1]+a[2]>a[3]);
		return 0;
	}
	if(v){
		for(int i=3;i<=n;i++){
			ans=(ans+(n-i+2)*(n-i+1)/2)%mo;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
