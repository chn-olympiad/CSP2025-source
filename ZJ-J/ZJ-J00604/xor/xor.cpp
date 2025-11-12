//xor ^ nonono
#include<bits/stdc++.h>
#define N 500010
using namespace std;
long long n,k,a[N],sx[N],ans=0,m;bool b=1;
long long f(int l,int r){
	if(l>r) {
		if(b) m=l,b=0;
		return 0;
	}
	long long cnt1=0;
	for(int i=l+1;i<=r;i++)
		for(int j=i;j<=r;j++)
			if(int(sx[j]^sx[i-1])==k){
//				cout<<i<<" "<<j<<"|"<<a[i-1]<<" "<<a[j]<<" ---"<<
//				int(sx[j]^sx[i-1])<<"--- "<<sx[i-1]<<" "<<sx[j]<<"\n";
				cnt1+=max(f(i,j),1ll);
				i=j+1;
			}
	return cnt1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
//	cout<<n<<" "<<k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sx[i]=sx[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<"\n";
//	if(n>100){
//		for(int i=1;i<=n;i++)
//			if(a[i]==k) ans++;
//		cout<<ans;
//		return 0;
//	}
	m=n;
	for(int l=0;l<m;l++){
		long long cnt=f(l,n);
		ans=max(ans,cnt);
//		cout<<cnt<<"\n-----------------------\n";
	}
	cout<<ans;
	return 0;
}
/* 
5 2
1 0 2 3 1
-->2
*/