#include<bits/stdc++.h>
using namespace std;

int a[5005];
long long mod=998244353;
long long ans=0;
int n,SP=0;

void dfs(int x,int ma,int cnt,int sum,int f){//第x条 最大ma 共cnt条 总长为sum f代表选了没有 
	if(x>n)return;
	
	if(cnt>=3 && (ma*2)<sum && f==1)ans=(ans+1)%mod;
	
	dfs(x+1,a[x+1],cnt+1,sum+a[x+1],1);//选 
	
	dfs(x+1,ma,cnt,sum,0);//不选 
	
	return;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	if(n<=2){
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		SP=max(a[i],SP);
	}
	sort(a+1,a+1+n);

	if(SP!=1){
		dfs(0,0,0,0,0);
		cout<<ans;
		return 0;
	}
	else {
		int now=2;
		for(int i=2;i<=n;i++){
			ans=(ans+(n-now))%mod;
			now++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
