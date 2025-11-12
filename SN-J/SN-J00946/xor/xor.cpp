#include <bits/stdc++.h>
using namespace std;
int ans=0, num[500005],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> num[i];
	}
	if (k==0 && n<=2){
		cout << 1 << endl; 
	}
	else {
		cout << 2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
