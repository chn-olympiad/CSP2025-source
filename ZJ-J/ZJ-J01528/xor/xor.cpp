#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001],b[100001];
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=(b[i-1]^a[i]);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i]^b[j])==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}