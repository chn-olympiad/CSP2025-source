#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans;
void dfs(int x,int sum,int cnt){
	if(x>n){
		if(sum==0) ans=cnt;
		return;
	}
	for(int i=x;i<=n;i++){
		sum^=a[i]; 
		if(sum==k){
			dfs(i+1,0,cnt+1);
		}
		if(ans) return;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}

