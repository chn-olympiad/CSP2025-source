#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
string s;
int n,m,ans,c[N],cnt1,tot,cntnot0;
bool f,ff[N];
void dfs(int sizz=0,int now=-1,int ouut=0){
	if(sizz==n-1){
		if(n-ouut>=m){
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(!ff[i]){
			ff[i]=1;
			if(c[now]<=ouut||s[now]=='0'){
				dfs(sizz+1,i,ouut+1);
//				printf("%d %d %d %d\n",now,c[now],ouut,sizz);
			}
			else dfs(sizz+1,i,ouut);
			ff[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1') cnt1++;
	}
	if(cnt1<m){
		printf("0");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)cntnot0++;
	}
	if(m==1){
		int how=1;
		for(int i=1;i<=n-1;i++){
			how*=i;
			how%=MOD;
		}
		ans=(cntnot0%MOD)*how%MOD;
		printf("%d",ans);
		return 0;
	}
	dfs();
	printf("%d",ans);
//	for(int i=0;i<n;i++){
//		if(s[i]!='1') f=true;
//	}
//	if(!f){
//		ans=1;
//		for(int i=1;i<=n;i++){
//			ans*=i;
//			ans%=MOD;
//		}
//		printf("%d",ans);
//	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2

*/