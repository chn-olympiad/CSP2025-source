#include<bits/stdc++.h>
using namespace std;
int a[500005],f[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=0,now=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		now^=x;
		if(f[now^k]!=0||now==k){
			ans++;
			memset(f,0,sizeof(f));
			now=0;
		}
		else f[now]++;
	}
	printf("%d\n",ans);
	return 0;
}
//freopen("xor.out","r",stdin);
//freopen("xor.in","w",stdout);