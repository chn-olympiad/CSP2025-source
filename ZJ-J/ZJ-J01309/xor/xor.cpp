#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
const int M=2e6+50;
int n,k,a[N],b[N],d[N],ans,x,c[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n+1;i++){
		scanf("%d",&a[i]);
		b[i]=(b[i-1]^a[i]);
	}
	c[0]=1;
	for(int i=2;i<=n+1;i++){
		d[i]=d[i-1];
		x=(b[i]^k);
		if(c[x]!=0){
			d[i]=max(d[i],d[c[x]]+1);
			ans=max(ans,d[i]);
		}
		c[b[i]]=i;
	}
	printf("%d",ans);
	return 0;
}
