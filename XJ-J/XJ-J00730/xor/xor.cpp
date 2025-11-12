#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int y = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 1){
			y++;
		}
	}
	if(k<0){
		cout << 0; 
	}
	else if(k==0){
		if(y==n){
			cout << n/2;
		}
		else{
			cout << y/2+n-y;
		}
	}
	if(k == 1){
		cout << y;
	}
	return 0;
}
