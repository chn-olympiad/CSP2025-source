#include<iostream>
#include<cstdio>
#define int long long
const int mod=998244353;
using namespace std;
int n,m;
char s[510];
int c[510];
int sa[510];
int jie[510];
int vis[510];
int find(int x,int num){
	if(num>=m){
		return jie[n-x];
	}
	if(x==n&&num>=m){
		return 1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}if(x-num>=c[i]){
			vis[i]=1;
			(ans+=find(x+1,num))%=mod;
			vis[i]=0;
		}else{
			if(sa[x+1]==0){
				vis[i]=1;
				(ans+=find(x+1,num))%=mod;
				vis[i]=0;
			}else if(sa[x+1]==1){
				vis[i]=1;
				(ans+=find(x+1,num+1))%=mod;
				vis[i]=0;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	jie[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		(jie[i]=jie[i-1]*i)%=mod;
	}
	for(int i=1;i<=n;i++){
		sa[i]=s[i]-'0';
//		printf("%lld ",sa[i]);
	}
//	if(m==1){
//		if(s[0]=='1'){
//			printf("%lld",jie[n]);
//		}else{
//			
//		}
//	}else{
	printf("%lld",find(0,0));
//	}
	return 0;
}
