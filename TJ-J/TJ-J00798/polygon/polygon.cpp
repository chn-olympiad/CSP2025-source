#include<bits/stdc++.h>
using namespace std;

int n,l[5007],lmax;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> l[i];
		lmax+=l[i];
	}
	sort(l,l+n);
	if(lmax>2*l[n-1]){
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
