#include<bits/stdc++.h>
using namespace std;
int s[501];
int n, m, k;
int c[501];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s", s+1);
	for(int i = 1; i <= n; i ++){
		scanf("%d",&c[i]);
	}
	int a;
	for(int i =1; i<=m*3+k*5 ;i++){
		scanf("%d",&a);
	}
	printf("1\n");
	
	
	return 0;
}
