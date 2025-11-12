#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],h;
bool q,w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==0){
			q=0;
		}
		if(a[i]>1){
			w=0;
		}
	}
	if(q){
		if(k==0){
			cout<<n/2;
			return 0;
		}
	}
	if(w){
		int q=0;
		for(int i=0;i<n;i++){
			q^=a[i];
			if(h==k){
				h++;
			}
		}
		cout<<h;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				h++;
				i=j;
				break;
			}
		}
	}
	cout<<h;
	return 0;
}
