#include <bits/stdc++.h>
using namespace std;
const int N=5E5+10;
int a[N],b[N],d[N];
signed main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	b[0]=k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
		b[i]=k^a[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1];
		for(int j=0;j<i;j++){
			if(b[j]==a[i]){
				d[i]=max(d[i],d[j]+1);
			}
		}
	}
	printf("%d",d[n]);
	return 0;
}
