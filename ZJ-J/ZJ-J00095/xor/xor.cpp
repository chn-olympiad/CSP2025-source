#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,k,a[N],last[M],f[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	fill(last+1,last+n+1,-1);
	last[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(last[s[i]^k]!=-1){
			f[i]=max(f[i],f[last[s[i]^k]]+1);
		}
		last[s[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}

