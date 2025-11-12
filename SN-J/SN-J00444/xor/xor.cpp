#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],d[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]^d[i-1];
	}
	int now=0,l=0;
	for(int i=1;i<=n;i++){
		now^=a[i];
		for(int j=l;j<i;j++){
			if((now^d[j])==k) {
				ans++;
				l=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
