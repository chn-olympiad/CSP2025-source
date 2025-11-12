#include <bits/stdc++.h>
using namespace std;

int n,k,sum=0;
int a[500011],b[500011];
int main(){

	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	b[0]=0;
	a[0]=0;
	for (int i=1;i<=n;i++){
		b[i]=(b[i-1] xor a[i]);
	}
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			int t=b[r] xor b[l-1];
			if (t==k){
				l=r;
				sum++;
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}