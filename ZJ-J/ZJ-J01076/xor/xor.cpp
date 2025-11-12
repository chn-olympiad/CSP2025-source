#include<bits/stdc++.h>
using namespace std;
int a[500005],k,n,b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
	}
	int s=0,l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if((b[i] xor b[j-1])==k){
				s++,l=i+1;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
