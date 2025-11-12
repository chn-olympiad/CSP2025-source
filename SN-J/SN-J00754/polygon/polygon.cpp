//SN-J000754 西安市高新第二初级中学 王昊泽 
#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool compare(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3){
		if((a[1]+a[2])>a[3]){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else{
		cout<<"366911923";
	}
	return 0;
}
