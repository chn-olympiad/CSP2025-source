#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	} 
	else cout<<n/m+1;
	return 0;
}
/*

*/