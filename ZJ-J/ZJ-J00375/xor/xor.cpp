#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool a[105];
bool pre[105];
bool cmp(bool x,bool y){
	return x!=y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2;
	return 0;
}
