#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,K,a[520000],b[520000],jxj=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i]^a[i]);
		b[i]=(b[i]^b[i-1]);
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if((b[k]^b[j-1])==K){
					sum++;
					j=k+1;
				}
			}
		}
		jxj=max(jxj,sum);
	}
	cout<<jxj;
	return 0;
}