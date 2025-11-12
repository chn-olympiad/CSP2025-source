#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXK=(1<<20)+5;
int n,k,a[MAXN],b[MAXK],cnt=0,num,f[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		if (a[i]==k){f[i]=f[i-1]+1;b[cnt]=i;continue;}
		num=cnt^k;
		if (b[num]==0){f[i]=f[i-1];b[cnt]=i;continue;}
		f[i]=max(f[i-1],f[b[num]]+1);
		b[cnt]=i;
	}
	cout<<f[n];
	return 0;
}
