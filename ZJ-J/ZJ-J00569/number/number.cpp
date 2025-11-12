#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string c;
	cin>>c;
	int l=c.size();
	for(int i=0; i<l; i++){
		if(c[i]<='9'&&c[i]>='0'){
			a[c[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--){
		for(int j=1; j<=a[i]; j++){
			cout<<i;
		}
	}
	return 0;
}
