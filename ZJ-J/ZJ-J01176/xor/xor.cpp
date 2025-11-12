#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1,o=1;i<=n;i++){
		for(int j=o;j<=i;j++){
			if((b[i]^b[j-1])==k){
				sum++;
				o=i+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
