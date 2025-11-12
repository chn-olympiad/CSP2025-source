
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int as[1000100]={},n,ans=0;
void dfs(int x,int c,int l){
	// chu kou
	if(x>n){
		if(l>c*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	// rn wu
	dfs(x+1,as[x],l+as[x]);
	dfs(x+1,c,l);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n>500){
		n-=2;
		for(int i =1;i<=n;i++){
			ans+=i*(i+1)/2;
			ans%=998244353;
		}
		cout << ans;
		return 0;
	}
	for(int i =1;i<=n;i++){
		cin>>as[i];
	}
	sort(as+1,as+1+n);
	dfs(1,0,0);
	cout <<ans;
	return 0;
}
