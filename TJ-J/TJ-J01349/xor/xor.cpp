#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010]={0},b[500010]={0},ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}
