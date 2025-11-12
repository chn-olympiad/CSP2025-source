#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,tot;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=0,cnt=0,x=0;
	while(r<=n){
		x=x^a[++r];
		if(x==k){
			while(l+1<r&&a[l]==a[r])
				l++,r--;
			x=0,l=r+1,cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}