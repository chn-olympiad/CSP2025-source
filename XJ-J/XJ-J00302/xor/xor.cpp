#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5;
LL n,a[N+10],k,ed,maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL l=1;l<=n;l++){
		bool flag=0;
		for(LL r=l;r<=n;r++){
			LL sum=0;
			for(LL i=l;i<=r;i++){
				sum=sum^a[i];
//				printf("a[%d]=%d,sum=%d\n",i,a[i],sum);
			}
			if(sum==k){
				ed=r;
				flag=1;
				maxn++;
//				printf("l=%d,r=%d,sum=%d,ans=%d\n",l,r,sum,maxn);
				break;
			}
//			if(l==894)
//			printf("l=%d,r=%d\n\n\n",l,r);
		}
		if(flag==1)
		l=ed;
	} 
	cout<<maxn;
	return 0;
}
