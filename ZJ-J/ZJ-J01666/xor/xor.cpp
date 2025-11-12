#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],b[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	int i=1,j=0;
	while(i<=n){
		for(int x=j;x<i;x++){
			if((b[i]^b[x])==k){
				ans++;
				j=i;
				break;
			}
		}
		i++;
	}
	printf("%d",ans);
	return 0;
}
