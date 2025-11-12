#include<bits/stdc++.h>
using namespace std;
int main() {
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k,a[500001];
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i+=2){
			if(a[i]==a[i+1])cnt++;
		}if(cnt==0)cout<<n;
		else cout<<cnt;
	}else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i+=2){
			if(a[i+1]-a[i]==1)cnt++;
		}cout<<cnt;
	}
	return 0;
}
