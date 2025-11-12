#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],f[200005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int q=0;
	if(k==0){
		if(a[1]==0)ans++;
		for(int i=2;i<=n;i++){
			if(a[i]==1&&a[i-1]==1)ans++;
			if(a[i]==0)ans++;
			a[i]=0;
		}
	}else{
		for(int i=1;i<=n;i++){
			q^=a[i];
			if(q==k)ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
