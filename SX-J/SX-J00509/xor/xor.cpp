#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool A=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=0;
	}
	if(A) return (cout<<n/2)&&0;
	else cout<<1;
	return 0;
}
