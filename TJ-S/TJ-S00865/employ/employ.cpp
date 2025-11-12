#include<bits/stdc++.h>
#define N 10000010
#define M 998244353
using namespace std;
int n, m, c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int a=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			a--;
		}
	}
	if(a<m){
		cout<<0;
		return 0;
	}
	if(m==1){
		unsigned long long ans=1;
		for(int i=a;i>=1;i--){
			ans*=i;
			ans%=M;
		}
		
		cout<<ans;
		return 0;
	}

	unsigned long long ans=1;
	for(int i=a;i>=1;i--){
		ans*=i;
		ans%=M;
	}
	cout<<ans%M;
	return 0;
}
