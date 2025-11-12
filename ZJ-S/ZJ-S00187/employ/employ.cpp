#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long fab(long long b,long long e){
	long long sum=1;
	for(int i=b;i<=e;i++){
		sum*=i;
		sum%=MOD;
	}
	return sum;
}
long long A(long long n,long long m){
	long long sum=1;
	if(n==m){
		return fab(1,n);
	}
	if(n>m) return A(m,n);
	else{
		return fab(n,m);
	}
}
long long poper,n,m,c[505],add;
bool flag;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) flag=true;
	}
	if(m==1){
		sort(c+1,c+n+1);
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				if(c[n]>=i+1){
					for(int j=1;j<=n;j++){
						if(c[j]>=i+1){
							printf("%lld",(fab(1,n-1)%MOD)*((n-j+1)%MOD)%MOD);
							return 0;
						}
					}
				}
				else{
					printf("0");
					return 0;
				}
			}
		}
		printf("0");
		return 0;
	}
	else if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		}
		if(flag==true) printf("0");
		else printf("%lld",A(n,n));
	}
	else{
		flag=false;
		for(int i=0;i<n;i++){
			if(s[i]=='0') flag==true;
		}
		if(flag==false){
			printf("%lld",fab(1,n));
			return 0;
		}
		else{
			printf("0");
			return 0
		}
	}
	return 0;
}
