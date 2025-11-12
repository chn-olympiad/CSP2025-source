#include <bits/stdc++.h>
using namespace std;

int is1 = 0,n,k,a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 0;i<n;i++){
		cin >> a[i];
		if (a[i] == 1){
			is1++;
		}
	}
	if((n == is1)&&(k==0)){
		cout << n-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//CCF HYZ orz
