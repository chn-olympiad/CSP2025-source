#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000005],sum;
int yihuo(int x,int y){
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k==0) for(int i=1;i<=n;i++) if(a[i]==0) sum++;
	else if(k==1) for(int i=1;i<=n;i++) if(a[i]==1) sum++;
	else if(k>=2){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				a[i]==0;
				sum++;
			}
		}
		
	}
	cout<<sum;
	return 0;
}
