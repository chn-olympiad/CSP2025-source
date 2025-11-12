#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin >> a[i];
	}
	for(int i=1;i<=a[1];i++){
		cin >> b[i];
	}
	if(a[2]%2==0){
		cout << 2;
	}
	else{
		cout << 1;
	}
}
