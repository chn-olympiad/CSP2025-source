#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
char s[508];
int c[508];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cntesy=0;
	for(int i=1;i<=n;++i){
		scanf("%c",&s[i]);
		if(s[i]=='1') ++cntesy;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	if(n==cntesy){
		ans=1;
		for(int i=n;i>=1;--i){
			ans*=i;
			ans%=MOD;
		}
		printf("%d",ans);
	}else{
		sort(c+1,c+n+1);
		int cntc=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='1'){
				
			}
		}
	}
	return 0;
}
