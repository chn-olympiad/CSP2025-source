#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k, cnt=0,a;
	cin>>n>>k;
	int f=0;
	for(long long i=1;i<=n;i++){
		cin>>a;
		if(a==k){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
