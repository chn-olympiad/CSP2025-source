#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],cnt,b[N];
int cal(int a,int b){
	int ans=0;
	for(int i=b-a+1;i>=1;i--){
		ans+=(i+1)*i;
	}
	return ans/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(n==3){
		int x=(a[1]+a[2]+a[3]>a[3]*2?1:0);
		printf("%d",x);
	}
	if(a[n]==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=cal(i,n);
		}
		printf("%d",ans%998244353);
	}
	
	return 0;
	
} 
