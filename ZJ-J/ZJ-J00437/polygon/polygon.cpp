#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,res,maxa;
int len[5010];
void dfs(int deep,int maxn,int sum,int chse,bool f){
	if(chse>=3&&maxn*2<sum&&f){
		++res;
		res%=mod;
	}
	if(deep>n) return ;
	dfs(deep+1,max(maxn,len[deep]),sum+len[deep],chse+1,true);
	dfs(deep+1,maxn,sum,chse,false);
}
int C(int n,int m){
	int sum=1;
	for(int i=n;i>=n-m+1;--i) sum*=i,sum%=mod;
	for(int i=m;i>=2;--i) sum/=i;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&len[i]);
		maxa=max(maxa,len[i]);
	}
	if(maxa==1){
		for(int i=n;i>=3;--i) res+=C(n,i),res%=mod;
		printf("%d",res);
	}
	else{
		dfs(1,0,0,0,false);
		printf("%d",res);
	}
	return 0;
}