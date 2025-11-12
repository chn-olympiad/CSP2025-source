#include<bits/stdc++.h>
using namespace std;
const long long maxn=505;
long long a[maxn],c[maxn],n,sum,m;
long long zero;
string s;
long long A(long long n,long long m){
	long long sum=1;
	for(long long i=n;i>=m;i--){
		sum*=i;	
		sum%=998244353;	
	}
	return sum%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)zero++;
	}
	for(long long i=0;i<s.size();i++){
		sum+=s[i]-'0';
	}
	if(sum<m){
		printf("0\n");
		return 0;
	}
	if(n==m){
		if(zero>0){
			printf("0\n");
			return 0;
		}
		printf("%lld\n",A(n,n)%998244353);
	}
	if(m==1){
		printf("%lld\n",(A(n-1,n-1)*(n-1))%998244353);
	}
}
