#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
const int MAXN=5e3+27;

int n,x;
long long ans=0;
int a[MAXN];
bool flag=true;

void dfs(int now,int chosen,int maxn,int sum,bool c) {
	if(chosen>=3&&maxn!=0&&maxn*2<sum&&c==false){
		ans++;
		ans%=MOD;
		c=true;
	}
	if(now>=n+1) return ;
	dfs(now+1,chosen,maxn,sum,c);
	dfs(now+1,chosen+1,max(a[now],maxn),sum+a[now],false);
	return ;
}

int main() {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	sort(a+1,a+n+1);
	
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans-=n*(n-1)/2;
		ans-=n;
		ans-=1;
		ans=(ans+MOD)%MOD;
		cout<<ans<<endl;
		return 0;
	}

	dfs(1,0,0,0,0);

	cout<<ans%MOD<<endl;

	return 0;
}