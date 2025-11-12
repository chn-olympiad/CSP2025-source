#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],x[25],y[25],flaga=1,flagb=1,sum,cntl[500010],cntr[500010];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1) flaga=0;
		if (a[i]!=1&&a[i]!=0) flagb=0;
	}
	if (flagb==1||flaga==1){
		for (int i=1;i<=n;i++){
			for (int s=1;s<=i;s++){
				if (cntl[s]==1||cntr[i]==1||cntl[i]==1||cntr[s]==1||cntl[i]<cntr[s]||cntr[s]<cntl[i]) continue;
				int ans=a[s];
				for (int j=s+1;j<=i;j++){
					if (a[j]==ans) ans=0;
					else ans=1;
				}
				if (ans==k){
					sum++;
					cntl[s]=1;
					cntr[i]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
//1 0 1 0

