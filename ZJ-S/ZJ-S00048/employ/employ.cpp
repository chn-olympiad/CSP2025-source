#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	unsigned long long n,m;
	cin>>n>>m;
	unsigned long long sum=1;
	for(int i=n;i>=(n-m+1);i--){
		sum*=i;
		sum%=M;
	}
	for(int i=1;i<=m;i++){
		sum/=i;
		sum%=M;
	}
	cout<<sum;
	return 0;
}
