/*
CSP-J 
姓名：魏诺澜
准考证号：SN-J01196
学校：西北工业大学附属中学 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,ans;
int a[5010];
void dfs(int k,int m,int sum,int maxx){
	if(k>n)return;
	if(m<2){
		dfs(k+1,m+1,sum+a[k],max(maxx,a[k]));	
		dfs(k+1,m,sum,maxx); 
	}else{
		if(sum+a[k]>max(maxx,a[k])*2){
			ans=((ans%MOD)+1)%MOD;
			dfs(k+1,m+1,sum+a[k],max(maxx,a[k]));
			dfs(k+1,m,sum,maxx);
			
			
		}else{
			dfs(k+1,m+1,sum+a[k],max(maxx,a[k]));
			dfs(k+1,m,sum,maxx);
	
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%MOD;
	return 0;
}
