#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105],ans;
char ch[105];
int c[105];
int sum[15];
int k[15],vis[15];
void dfs(int now){
	if(now==n){
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int flag=0;
	scanf("%d%d",&n,&m);
	
	cin>>ch;
	for(int i=0;i<n;i++){
		s[i+1]=ch[i]-'0',sum[i+1]=s[i+1]+sum[i];	
		if(s[i+1]==0)flag=1;
	//	printf("%d ",s[i+1]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)cnt++;
	}
	if(flag==0){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		printf("%lld",ans);
	}
}
