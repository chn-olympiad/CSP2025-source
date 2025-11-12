#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],qzh[500050],l=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1] ^ a[i];
	}
	for(int i=1;i<=n;i++){
		if(qzh[l-1] ^ qzh[i]==k){
			ans++;
			l=i+1;
		}
	}
	cout<<ans;
	return 0;
}
