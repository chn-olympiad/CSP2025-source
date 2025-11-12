#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int maxx=0,ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		ans+=a[i];
	}
	if(n<3){
		printf("0");
		return 0;
	}
	if(ans>maxx*2){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}