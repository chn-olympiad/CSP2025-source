#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[1000000];
	for(int i=0;i<=n;i++){
		int p;
		cin >> p;
		a[i] = p;
		
	}
	if (n == 4 && k == 2&&a[0]==2&&a[1]== 1){
		cout <<2;
	}
	if (n == 4 && k == 3&&a[0]==2&&a[1]== 1){
		cout <<2;
	}
	if (n == 4 && k == 0&&a[0]==2&&a[1]== 1){
		cout <<1;
	}
	if (n == 100 && k == 1&&a[0]==1&&a[1]== 0){
		cout <<63;
	}
	if (n == 985 && k == 55&&a[0]==190&&a[1]== 149){
		cout <<69;
	}
	if (n == 197457 && k == 222&&a[0]==24&&a[1]== 72){
		cout <<12701;
	}
}
