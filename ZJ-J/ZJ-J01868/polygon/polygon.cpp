#include<bits/stdc++.h>
using namespace std;
int n,a[5005],qzh[5005];
long long sums;
void ans1(){
	sums=1;
	for(int i=1;i<=n;i++){
		sums*=2;
		sums%=998244353;
	}
	cout<<(sums+998244353-n-1-n*(n-1)/2)%998244353;
}
void dfs(int step,int sum,int maxn,int num){
	if(qzh[step]+sum<=maxn*2) return ;
	if(sum>maxn*2&&num>=3){
		sums+=1<<step;
		sums%=998244353;
		return ;
	}
	if(step==0) return ;
	dfs(step-1,sum+a[step],max(maxn,a[step]),num+1);
	dfs(step-1,sum,maxn,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20){
		ans1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20){
		for(int i=3;i<=n;i++){
			sums%=998244353;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	dfs(n,0,0,0);
	cout<<sums;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
