//白祖铭，SN-J00838，宝塔区第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,a[100001],
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	if(a[1]+a[2]+a[3]>a[3]*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
