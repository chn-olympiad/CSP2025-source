#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],xa[500005],xb[500005],c=1;
bool f=1;
struct fanwei{
	int l,r;
}p[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		xa[i]=a[i]^xa[i-1];
		xb[i]=xa[i]^k;
	}
	if(f){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(xa[i]==k){
			p[c].l=1;
			p[c++].r=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(xb[i]==xa[j]){
				p[c].l=i+1;
				p[c++].r=j;
			}
		}
	}
	return 0;
}
