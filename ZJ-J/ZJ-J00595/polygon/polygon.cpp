#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool v[5010];
int cnt=0;
const int MOD=998244353;
void dfs(int m,int sum,int mx,int level){
	if(m==0){
		if(sum>(mx*2)){
			cnt++;
			cnt=cnt%MOD;
		}
		return;
	}
	for(int i=level;i<=n-m+1;i++){
		if(!v[i]){
			v[i]=true;
			dfs(m-1,sum+a[i],max(mx,a[i]),i+1);
			v[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int m=3;m<=n;m++){
		dfs(m,0,0,1);
		memset(v,0,sizeof(v));
	}
	printf("%d",cnt);
	return 0;
}