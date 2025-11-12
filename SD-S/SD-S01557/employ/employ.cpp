#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=505,mod=998244353;
long long n,m,c[N],a[N],ans,Cnt;
string s;
bool f[N];
void dfs(long long x,long long y){
	if(y>n-m)return ; 
	if(x==n){
		ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			continue;
		}
		else{
			f[i]=1;
			a[x+1]=i;
			if(s[x]=='1'){
				if(y>=c[i]){
					dfs(x+1,y+1);
				}
				else{
					dfs(x+1,y);
				}
			}
			else{
				dfs(x+1,y+1);
			}
			a[x+1]=0;
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	bool Flag=0;
	for(int i=0;i<=n-1;i++){
		if(s[i]!='1'){
			Flag=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0){
			Cnt++;
		}
	}
	if(Flag==0){
		long long ANS=1;
		for(int i=1;i<=n-Cnt;i++){
			ANS*=i;
			ANS%=mod;
		}
		printf("%lld",ANS);
		return 0;
	}
	dfs(0,0); 
	printf("%lld",ans);
	return 0;
}
