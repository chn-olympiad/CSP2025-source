#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	scanf("%d",&n);
	int a[n+5];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
	    int m=max(a[1],a[2]);
	    m=max(m,a[3]);
		if((a[1]+a[2]+a[3])>(m*2)){
            printf("1");
            return 0;
		}
	}
    printf("%d",s);
	return 0;
}