#include<bits/stdc++.h>
using namespace std;
const int N=550,mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	
	int n,m,a[N];
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	int res=1;
	for(int i=m+1;i<=n;i++){
		res=(res*i)%mod;
	}
	int num=1;
	for(int i=1;i<=(n-m);i++){
		num=(num*i)%mod;
	}
	cout<<(res/num)%mod;
	
	
	
	return 0;
}