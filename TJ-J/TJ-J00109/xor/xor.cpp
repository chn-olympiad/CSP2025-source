#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1010];
int qzh[1010]; 
int maxn=-1;
void in(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			qzh[i]=(qzh[i-1]^a[i]);
		}else qzh[i]=a[i];
	} 
}
void dfs(int start,int x,int ans){
	if(x>n) maxn=max(ans,maxn);
	else{
		if((a[x]^a[start-1])==k) {
			dfs(x+1,x+1,ans+1);
		}else{
			dfs(start,x+1,ans);
			dfs(x+1,x+1,ans);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	in();
	dfs(1,1,0);
	cout<<maxn;
	return 0;
}
