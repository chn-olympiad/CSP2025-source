#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
string s;
int p[505];
int c[505];
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	s=" "+s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='0'){
			k++;
		}
	}
	if(n-k<m){
		printf("0");
		return 0;
	}
	if(k==0){
		int f=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				f=0;
				break;
			}
		}
		if(f){
			long long fac=1;
			for(int i=1;i<=n;i++){
				fac=fac*i%mod;
			}
			printf("%lld",fac);
			return 0;
		}
	}
	k=0;
	for(int i=1;i<=c[i];i++){
		if(c[i]==0){
			k++;
		}
	}
	if(n-k<m){
		cout<<0;
		return 0;
	}
	if(n==m){
		long long fac=1;
		for(int i=1;i<=n;i++){
			fac=fac*i%mod;
		}
		printf("%lld",fac);
		return 0;
	}
	if(n==1){
		long long fac=1;
		for(int i=1;i<=n;i++){
			fac=fac*i%mod;
		}
		printf("%lld",fac);
		return 0;
	}
	sort(c+1,c+1+n);
	cout<<0;
	return 0;
}

