#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n%2==0){
		cout<<n*n/2/2;
	}
	else{
		cout<<(n+1)*(n/2)/2;
	}
	return 0;
}
