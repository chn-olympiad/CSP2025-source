#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int num = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		num += a[i];
	}
	sort(a+1,a+n+1);
	if(num > a[n]*2){
		cout << 1;
	}else cout << 0;
	
	return 0;
}
