#include<bits/stdc++.h>
using namespace std;
string s;
long long a[500005],n,k,pre[500005],Max;
void dfs(long long node,long long cnt){
	if(node==n+1){
		Max = max(Max,cnt);
		
		return;
	}
	for(long long i = node;i<=n;i++){
		if((pre[i]^pre[node-1]) == k){
			
			dfs(i+1,cnt+1);
			
			
		}
		else{
			dfs(i+1,cnt);
		}
	}
}
bool ok;
int main(){
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	cin>>n>>k;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	pre[1] = a[1];
	for(long long i = 2;i<=n;i++){
		pre[i] = a[i]^pre[i-1];
	}
	
	dfs(1,0);
	cout<<Max;
	return 0;
}
