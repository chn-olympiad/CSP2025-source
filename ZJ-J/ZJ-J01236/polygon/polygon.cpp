#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,maxn=5005;
int n,a[maxn],ans;
void dfs(int sum,int ma,int cnt,int d){
	if(sum>ma*2&&cnt>=3){
		ans++;
		ans%=mo;
	}
	if(d>n)return;
	dfs(sum+a[d],ma=max(ma,a[d]),cnt+1,d+1);
	dfs(sum,ma,cnt,d+1);
}
void dfs2(int cn,int de){
	if(cn>=3){
		ans++;
		ans%=mo;
	}
	if(de>n)return;
	dfs2(cn+1,de+1);
	dfs2(cn,de+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		dfs(0,0,0,1);
		cout<<ans;
	}
	else{
		dfs2(0,0);
		cout<<ans;
	}
	return 0;
}
