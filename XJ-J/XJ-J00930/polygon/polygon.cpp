#include <bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],last = 0,cnt = 0,is1 = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i<n;i++){
		cin >> a[i];
		if (a[i] == 1){
			is1++;
		}
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1] > a[2]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else if((n == is1)&&(n!=3)){
		cout << ((n-1)*(n-2))/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//CCF HYZ orz
