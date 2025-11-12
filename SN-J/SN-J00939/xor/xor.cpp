#include<bits/stdc++.h>
using namespace std;
long long n,k,mx=-1,cnt;
const int N=5*1e5;
int num[N];
bool vis[N];
void dfs(int st){
	if(st>n){
		return;
	}
	int cn1=0;
	for(int i=st;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		cn1=cn1^num[i];
		vis[i]=1;
		if(cn1==k){
			cnt++;
			dfs(i+1);
			vis[i]=0;		
		}
	}
	mx=max(mx,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		dfs(i);
	}
	printf("%lld",mx);
	return 0;
}

