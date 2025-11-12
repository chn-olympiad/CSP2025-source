#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n,k,a[N+10],f[N+10];
int wrk1(int r,int t) {
	for(int i=r; i>=0; i--) {
		t=t^a[i];
		if(t==k)
			return i;
	}
	return N+1;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]==0)
			i--,n--;
	}
	f[N+1]=-1;
	f[0]=a[0]==k?1:0;
	for(int i=1; i<n; i++) {
		if(a[i]==k)
			f[i]=f[i-1]+1;
		else {
			int p=wrk1(i-1,a[i]);
			if(p==0)
				f[i]=1;
			else if(p!=N+1)
				f[i]=f[p-1]+1;
		}
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n-1];
	return 0;
}
