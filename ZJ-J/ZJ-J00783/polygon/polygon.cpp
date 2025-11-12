#include<bits/stdc++.h>
using namespace std;

int n;
int a[10005];
bool vis[10050];
long long ans = 0;
long long s[10005];

bool check(int num,long long sum){
	if(num<3){
		return 0;
	}
	int mx =0;
	for(int i = 1;i<=n;i++){
		if(vis[i]){
			mx = max(mx,a[i]);
		}
	}
	if(sum>2*mx){
		return 1;
	}
	else{
		return 0;
	}
}

void dfs(int i,int num,long long sum,int mux){
	if((s[n]-s[i-1]+sum)<=2*mux)return;
	if(i>n){
		if(check(num,sum)){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	vis[i] = 1;
	dfs(i+1,num+1,sum+a[i],max(mux,a[i]));
	vis[i]=0;
	dfs(i+1,num,sum,mux);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i] = s[i-1]+a[i];
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
