#include<bits/stdc++.h>
using namespace std;
int n;
int sum=0;
int a[4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int mx=max(a[1],max(a[2],a[3]));
	if(mx*2<sum){
		printf("1");
	}else{
		printf("0");
	}
	//wo bu hui
	return 0;
}









