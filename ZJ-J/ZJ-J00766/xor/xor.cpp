#include<bits/stdc++.h>
using namespace std;
int t,n,k,l;
int a[500009],sum[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=l+1;j<=i;j++){
			int r=sum[i]^sum[j-1];
			if(r==k){
				t++;
				l=i;
				break;
			}
		}
	}
	cout<<t;
}
