#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,l;
int q[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i]=(q[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if((q[i]^q[j])==k){
				l=i;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

