#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[500005];
void f(int m,int sum){
	for(int i=m+1;i<=n;i++){
		int s=0;
		for(int j=1;j<=n-i+1;j++){
			s=s^a[i+j-1];
			if(s==k){

				f(i+j-1,sum+1);
				break;
			}
		}		
	}
	ans=(sum>ans)?sum:ans;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=n-i+1;j++){
			s=s^a[i+j-1];
			if(s==k){
				f(i+j-1,1);
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
