#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],sum,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	l=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
			l=i+1;
			continue;
		}
		for(int j=l;j<i;j++){
			if((f[i-1]^f[j-1])==(k^a[i])){
				sum++;
				l=i+1;
				break;
			}
		}
	}
	cout<<sum;
}
