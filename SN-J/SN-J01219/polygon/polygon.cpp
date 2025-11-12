#include<bits/stdc++.h>
using namespace std;
int m[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m[i]);
	}
	sort(m+2,m+4);
	if(n<3){printf("0");return 0;}
	if(n==3){
	if(m[2]+m[3]>m[1]){printf("1");return 0;
	}
	else printf("0");}
	return 0; 
}
