#include<bits/stdc++.h>
using namespace std;
long long n,q,a[911111],t,tz;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)t++;
		if(a[i]==0)tz++;
	}
	ans=t/2+tz;
	cout<<ans;
}
