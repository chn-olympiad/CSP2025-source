#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int k,n,a[N],yh,maxn=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k)maxn++;
	}
	cout<<maxn;
	return 0;
} 
