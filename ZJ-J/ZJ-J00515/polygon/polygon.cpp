#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum;
int a[5099];
int s[5099];
void dfs(int id,int maxn,int ss){
	if(ss>maxn){
		sum++;
		sum%=998244353;
		return;
	}
	for(int i=id-1;i>=1;i--){
		//if(s[i]+ss<=maxn) return;
		dfs(id-1,maxn,ss+a[i]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	if(n==3){
		if(a[1]+a[2]>a[3]&&abs(a[3]-a[1])<a[2]) cout<<1;
		else cout<<0;
		return 0;
	}	
	
	
	//for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		
	for(int i=n;i>=3;i--){
		if(s[i-1]<=a[i]) continue;
		dfs(i,a[i],0);
	}
		
	cout<<sum;
	
	return 0;
}
