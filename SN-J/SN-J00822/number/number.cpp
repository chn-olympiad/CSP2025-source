#include<bits/stdc++.h>
using namespace std;
string r;
int n;
int a[1000010]={-1};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> r;
	n=r.size();
	for(int i=0;i<n;i++){
		a[i]=r[i]-'0';
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i] <= 9){
			cout << a[i];
		}
	}
	return 0;
}
