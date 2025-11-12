#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100000],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
