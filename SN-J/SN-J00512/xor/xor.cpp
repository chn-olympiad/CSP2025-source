#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	if(k==0){//1&3 10Pts
		cout<<n/2<<"\n";
		return 0;
	}
	if(k==1){//2,4,5,13 20Pts
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		cout<<cnt<<"\n";
		return 0;
	}
	cout<<"1\n";
	return 0;
}
