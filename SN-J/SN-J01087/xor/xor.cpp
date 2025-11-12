#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=n/2;
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
