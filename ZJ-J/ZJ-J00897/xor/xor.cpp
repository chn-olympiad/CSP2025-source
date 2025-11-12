#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int cnt,a[N],s[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j;cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) s[i]=a[i]^s[i-1];
	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<"\n";
			if((s[j]^s[i])==k) {
//				cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" "<<k<<"\n";
				cnt++;
				break;
			}
		}
		i=j-1;
	}
	cout<<cnt<<"\n";
	return 0;
}
/*
4 0
2 1 0 3
*/
