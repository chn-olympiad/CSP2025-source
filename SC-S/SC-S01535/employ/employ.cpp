#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long m;
long long cnt;
long long A[200000]; 
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(A[i]==0){
			cnt++;
		}
	}
	if((n-cnt+1)<m){
		cout<<0<<endl;
	}else{
		long long sum=1;
		long long s=n-cnt+1;
		for(int i=s-1;i>=1;i--){
			sum=sum*s%mod;
		}
		cout<<sum<<endl;
	}
    fclose(stdin);
	fclose(stdout);


	return 0;
}
