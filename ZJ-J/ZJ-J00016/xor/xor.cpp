#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],t,r,m,w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];m=max(m,a[i]);
		if(a[i]==1){
			w++;
		}
	}
	if(k==1&&m==1){
		cout<<w;
		return 0;
	}
	r=n+1;
	for(int i=1;i<=n+1;i++){
		if(i>r){
			t++;
			r=n+1;
		}
		long long c=0;
		for(int j=i;j<=r;j++){
			c^=a[j];
			if(c==k){
				r=j;
				break;
			}
		}
	}
	cout<<t;
	return 0;
}
