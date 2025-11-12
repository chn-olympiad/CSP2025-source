#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,k,a[N],s[N],f[N]; 

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i;j>=1&&f[j-1]+1>f[i];j--){
			if((s[i]^s[j-1])==k){
				f[i]=f[j-1]+1;
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
} 
