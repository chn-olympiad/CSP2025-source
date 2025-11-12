#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
bool s[510];
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int x;
	bool A_lock=true,X_lock=true;
	int X_solve=0,X_solve2=0;
	for(int i=0;i<n;i++){
		cin>>x;
		s[i]=(x==1);
		if(x==0){
			A_lock=false;
			if(X_lock==true){
				X_solve++;
			}
		}
		else{
			X_lock=false;
		}
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]>X_solve)X_solve2++;
	}
	if(A_lock||X_solve==0){
		long long ans=1;
		for(long long i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==1){
		long long x1=X_solve2,x2=n-X_solve2,l=X_solve;
		if(x1<l){
			cout<<(-1)%mod;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else{
			long long ans=x2;
			long long j=1;
			for(long long i=x2;i>x2-l;i--){
				long long x3=i;
				while(j<=l && x3%j==0){
					x3=x3/j;
					j++;
				}
				ans=(ans*i)%mod;
			}
			for(int i=2;i<=x1;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
}
