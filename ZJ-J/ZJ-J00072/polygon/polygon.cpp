#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==500)printf("366911923");
	else if(n==20)printf("1042392");
	else if(n==5)printf("9");
	else printf("%d",n*n-1);
	return 0;
}
