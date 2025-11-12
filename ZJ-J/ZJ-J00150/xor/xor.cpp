#include<bits/stdc++.h>
using namespace std;
int a[500005];
int qxor(int l,int r) {
	int ans=a[l];
	for(int i=l+1;i<=r;i++)
		ans=ans^a[i];
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int maxn=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(qxor(j,i)==0) maxn=abs(j-k)+1;
	cout<<maxn;
	return 0;
}

