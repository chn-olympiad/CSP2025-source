#include<bits/stdc++.h>
using namespace std;
int n,a[510];
long long ans,mod=998244353;
void dfs(int d,int s,int ma,int side){
	if(d==n+1){
		if(s>ma*2&&side>=3){
			ans++;ans%=mod;
		}
		return;
	}
	dfs(d+1,s,ma,side);
	dfs(d+1,s+a[d],max(ma,a[d]),side+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		cout<<(n-1)*(n-2)/2;
	}
	else{
	    dfs(1,0,0,0);
	    cout<<ans;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}//O(2^n)
