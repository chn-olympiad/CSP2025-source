#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
#define int long long
int n,m; 
int f(int x){
	if(x==1||x==0) return 1;
	return f(x-1)%M*x%M;
}
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n;
	cout<<f(n)%M;
	return 0;
}

