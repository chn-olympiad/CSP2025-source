#include<bits/stdc++.h>
using namespace std;
//#define int long long 
const int mod=998244353;
int n,m;
string s;
const int maxn=1e6+5;
int c[maxn];
long long ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
    cin>>s;
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	int f=0;
	for(int i=1;i<=10;++i){
		if(s[i]!=s[i-1]||s[i]!='1'){
			f=1;
		}
	}
	if(f){
    if(m==1){
		printf("%d",n);
	}
	}else{
		for(int i=n,j=m;i>n-m;--i){
			if(j>0){
				ans*=i/m;
			}else{
				ans*=i;
			}
			ans%=mod;
//		ans*=i;
	
		}	
		printf("%lld",ans);
	}

	return 0;
}