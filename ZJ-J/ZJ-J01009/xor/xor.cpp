#include<bits/stdc++.h>
using namespace std;
int n,k,f[500001],a[500001],b[500001],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];
		f[i]=f[i-1];
		for(int j=i-1;j>=0&&f[j]==f[j+1];j--){
			int t=b[i]^b[j];
			if(t==k) f[i]=max(f[j]+1,f[i]);
			else f[i]=max(f[j],f[i]);
		}
	}
	cout<<f[n];
}