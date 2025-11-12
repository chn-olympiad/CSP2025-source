#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,xsum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		xsum[i]=xsum[i-1]^a[i];
	}
	int l=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			l=i,ans++;
//			cout<<i<<' '<<i<<"\n";
			continue;
		}
		for(int j=i-1,j2=l+1;j>l&&j2<i;j--,j2++){
			if((xsum[i]^xsum[j-1])==k||(xsum[i]^xsum[j2-1])==k){
				l=i,ans++;
//				cout<<j<<' '<<i<<"\n";
				break;
			}
//			if((xsum[i]^xsum[j2-1])==k){
//				l=i,ans++;
//				cout<<j2<<' '<<i<<"\n";
//				break;
//			}
		}
	}
	printf("%d",ans);
	return 0;
}
