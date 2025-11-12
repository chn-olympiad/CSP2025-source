#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int mod=998244353;
int dif[505],dis[505],n,m,sum[505];
string s;
long long ans=0;
void dfs(int idx,int cnt,int add){
	if(n-add<m){
		return;
	}
	if(idx==n+1){
		if(cnt>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==0){
			dis[i]=1;
			if(sum[idx]+add>dif[i] || s[idx-1]=='0'){
				dfs(idx+1,cnt,add+1);
			}
			else{
				dfs(idx+1,cnt+1,add);
			}
			dis[i]=0;
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&dif[i]);
	}
	for(int i=0;i<n;i++){
		int ff=0;
		if(s[i-1]=='0'){
			ff=1;
		}
		sum[i+1]+=sum[i]+ff;
	}
	if(sum[n]==0){
		long long fac=1;
		for(int i=1;i<=n;i++){
			fac*=i;
			fac%=mod;
		}
		printf("%lld",fac);
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

